#!/usr/bin/env python3
import os
import re
import json
import argparse
from datetime import datetime
import openpyxl
import requests
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

def call_gemini(prompt, api_key=None):
    # Load API key from env if not provided
    if api_key is None:
        api_key = os.getenv('GEMINI_API_KEY')
    # Construct URL with actual key
    url = f"https://generativelanguage.googleapis.com/v1beta/models/gemini-2.0-flash:generateContent?key={api_key}"
    headers = {"Content-Type": "application/json"}
    payload = {
        "contents": [{
            "parts": [{"text": prompt}]
        }]
    }
    # Send request
    resp = requests.post(url, headers=headers, json=payload)
    try:
        resp.raise_for_status()
    except requests.HTTPError:
        print("Gemini HTTP error:", resp.status_code, resp.text)
        raise
    resp_json = resp.json()
    candidates = resp_json.get('candidates', [])
    if candidates:
        text = _extract_output(candidates[0])
        if text:
            return text
    # Fallback: show full response for debugging
    import json as _json
    print("Unexpected or empty Gemini response:\n", _json.dumps(resp_json, indent=2))
    raise ValueError("No valid text found in Gemini response")

def _extract_output(candidate):
    """Extract text from Gemini response candidate."""
    try:
        parts = candidate.get('content', {}).get('parts', [])
        if parts:
            return parts[0].get('text', '').strip()
    except (KeyError, IndexError):
        pass
    return None


def extract_fields(comment_block, category, api_key):
    prompt = f"Extract JSON with keys problem_number, title, difficulty, space_complexity, time_complexity, runtime, key_concept, technique from the following C++ comment block.\nCategory: {category}\nComment: ```{comment_block}```\nProvide only valid JSON."
    content = call_gemini(prompt, api_key)

    # Extract JSON from markdown code block if present
    if content.strip().startswith('```'):
        # Find content between triple backticks
        match = re.search(r'```(?:json)?\s*([\s\S]*?)\s*```', content)
        if match:
            json_str = match.group(1).strip()
        else:
            print(f"Could not extract JSON from markdown: {content}")
            raise ValueError("JSON extraction failed")
    else:
        json_str = content.strip()

    try:
        return json.loads(json_str)
    except json.JSONDecodeError:
        print(f"Failed to parse JSON from content: {content}")
        raise


def read_comment_block(file_path):
    with open(file_path, 'r') as f:
        lines = []
        for line in f:
            if line.strip().startswith('//'):
                lines.append(line.strip()[2:].strip())
            elif lines:
                break
    return '\n'.join(lines)

def append_to_excel(excel_path, row):
    excel_path = os.path.expanduser(excel_path)
    print(f"Saving to: {os.path.abspath(excel_path)}")

    # Create workbook if it doesn't exist
    if not os.path.exists(excel_path):
        wb = openpyxl.Workbook()
        ws = wb.active
        # Add headers if creating new file
        headers = ["Date", "Day", "Problem #", "Title", "Difficulty", "Category",
                   "Space Complexity", "Time Complexity", "Runtime", "Key Concept",
                   "Technique", "Solution Link"]
        ws.append(headers)
    else:
        wb = openpyxl.load_workbook(excel_path)
        ws = wb.active
    
    row = [str(item) if item is not None else '' for item in row]
    ws.append(row)
    wb.save(excel_path)
    
def check_if_problem_exists(excel_path, problem_title):
    """Check if a problem with the given title already exists in the Excel file."""
    excel_path = os.path.expanduser(excel_path)
    if not os.path.exists(excel_path):
        return False  # Excel file doesn't exist, so problem doesn't exist
    
    wb = openpyxl.load_workbook(excel_path)
    ws = wb.active
    
    title_col = 4
    
    # Check each row for the title
    for row in range(2, ws.max_row + 1):  # Start from row 2 to skip header
        cell_value = ws.cell(row=row, column=title_col).value
        if cell_value and cell_value.strip() == problem_title:
            return True
    
    return False


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Automate LeetCode Excel updates')
    parser.add_argument('files', nargs='+', help='Paths to C++ files to process')
    parser.add_argument('--excel', required=True, help='Path to the Excel file (.xlsx)')
    parser.add_argument('--day', type=int, required=True, help='Day count for the session')
    parser.add_argument('--api-key', help='Gemini API key')
    args = parser.parse_args()

    today = datetime.today().strftime('%m/%d/%Y')

    for file_path in args.files:
        category = os.path.basename(os.path.dirname(file_path))
        comment_block = read_comment_block(file_path)
        data = extract_fields(comment_block, category, args.api_key)
        # Check if problem already exists in Excel
        if check_if_problem_exists(args.excel, data.get('title')):
            print(f"Problem '{data.get('title')}' already exists in the Excel file. Skipping.")
            continue
        
        row = [
            today,
            args.day,
            data.get('problem_number'),
            data.get('title'),
            data.get('difficulty'),
            category,
            data.get('space_complexity'),
            data.get('time_complexity'),
            data.get('runtime'),
            data.get('key_concept'),
            data.get('technique'),
            ''  # link to solution (manual)
        ]
        append_to_excel(args.excel, row)
