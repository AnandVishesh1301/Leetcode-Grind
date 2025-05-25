// Evaluate Reverse Polish Notation
// Given a list of tokens representing an arithmetic expression in **Reverse Polish Notation (RPN)**,
// evaluate the expression and return the result as an integer.
//
// Reverse Polish Notation (Postfix Notation):
// - Operators come **after** their operands
// - The expression is evaluated using a **stack**
//
// Valid operators: '+', '-', '*', '/' (integer division, truncate toward 0)
// Each token is either:
//   - A valid integer operand (e.g., "42", "-5")
//   - A valid operator (e.g., "+", "*")
//
// Example 1:
//   Input : tokens = ["4","13","5","/","+"]
//   Output: 6        → (4 + (13 / 5))
//
// Example 2:
//   Input : tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
//   Output: 22
//
// Approach:
// - Use a **stack** to simulate evaluation of the expression
// - Traverse the input tokens:
//     - If the token is a number, push it to the stack
//     - If the token is an operator:
//         - Pop the top two elements from the stack
//         - Apply the operator on them (lhs op rhs)
//         - Push the result back onto the stack
// - After processing all tokens, the result will be the top of the stack
//
// Time Complexity: **O(N)** — each token is processed once
// Space Complexity: **O(N)** — for storing operands in the stack
//
// Time Stats (from LeetCode submission):
//   Runtime : 2 ms  
//   Beats   : 44.75 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 17.12 MB
//   Beats        : 37.07 % of C++ users


//Solution
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        using BinOp = std::function<int(int, int)>;
        stack<int> s;

        // Map each operator to its corresponding lambda function
        const unordered_map<string, BinOp> opTable = {
            { "+", [](int a, int b) { return a + b; } },
            { "-", [](int a, int b) { return a - b; } },
            { "*", [](int a, int b) { return a * b; } },
            { "/", [](int a, int b) { return a / b; } }  // Integer division truncates toward 0
        };

        // Iterate over each token in the input
        for (const string& token : tokens) {
            auto it = opTable.find(token);
            if (it != opTable.end()) {
                // Operator found → pop two operands from stack
                int rhs = s.top(); s.pop();  // Right-hand side
                int lhs = s.top(); s.pop();  // Left-hand side
                int result = it->second(lhs, rhs);  // Apply the operator
                s.push(result);  // Push result back to stack
            } else {
                // Operand found → convert to int and push
                s.push(stoi(token));
            }
        }

        return s.top();  // Final result is on top of the stack
    }
};
