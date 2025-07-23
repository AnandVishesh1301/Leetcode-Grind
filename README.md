# 🧩 NeetCode 150+ Solutions Repository

Welcome to my comprehensive collection of **LeetCode problem solutions**, organized following the **NeetCode 150 series** pattern. This repository contains well-documented C++ solutions with detailed explanations, complexity analysis, and multiple approaches where applicable.

## 📚 Repository Overview

This repository follows the structure and question selection of the popular **NeetCode 150** series, providing solutions to essential coding interview problems across major data structures and algorithms topics. Each solution includes:

- ✅ **Complete problem description**
- ✅ **Multiple solution approaches** (where applicable)
- ✅ **Time and Space complexity analysis**
- ✅ **Detailed algorithmic explanations**
- ✅ **LeetCode performance statistics**
- ✅ **Clean, well-commented C++ code**

---

## 🗂️ Repository Structure

### 📁 Arrays & Hashing
**Problems focused on array manipulation, hash maps, and frequency counting.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `contains_duplicate.cpp` | Contains Duplicate | O(n) | O(n) | Hash Set |
| `valid_anagram.cpp` | Valid Anagram | O(n) | O(1) | Character Frequency |
| `two_sum.cpp` | Two Sum | O(n) | O(n) | Hash Map |
| `group_anagrams.cpp` | Group Anagrams | O(n×m) | O(n×m) | Hash Map + Sorting |
| `top_k_frequent_elements.cpp` | Top K Frequent Elements | O(n) | O(n) | Bucket Sort |
| `product_of_array_except_self.cpp` | Product of Array Except Self | O(n) | O(1) | Prefix/Suffix Products |
| `valid_sudoku.cpp` | Valid Sudoku | O(1) | O(1) | Hash Set Validation |
| `longest_consecutive_sequence.cpp` | Longest Consecutive Sequence | O(n) | O(n) | Hash Set |
| `majority_element.cpp` | Majority Element | O(n) | O(n) | Hash Map Frequency |

### 📁 Two Pointers
**Problems using two-pointer technique for efficient array/string processing.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `valid_palindrome.cpp` | Valid Palindrome | O(n) | O(1) | Two Pointers |
| `two_sum_II_input_array_is_sorted.cpp` | Two Sum II | O(n) | O(1) | Two Pointers |
| `3sum.cpp` | 3Sum | O(n²) | O(1) | Two Pointers + Sorting |
| `container_with_most_water.cpp` | Container With Most Water | O(n) | O(1) | Two Pointers |
| `trappinng_rain_water.cpp` | Trapping Rain Water | O(n) | O(1) | Two Pointers |
| `boats_to_save_people.cpp` | Boats to Save People | O(n log n) | O(1) | Greedy + Two Pointers |
| `reverse_a_string.cpp` | Reverse String | O(n) | O(1) | Two Pointers |

### 📁 Sliding Window
**Problems using sliding window technique for substring/subarray optimization.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `best_time_to_buy_sell_stock.cpp` | Best Time to Buy and Sell Stock | O(n) | O(1) | Sliding Window |
| `longest_substring_without_repeating_characters.cpp` | Longest Substring Without Repeating Characters | O(n) | O(n) | Sliding Window + Hash Map |
| `longest_repeating_character_replacement.cpp` | Longest Repeating Character Replacement | O(n) | O(1) | Sliding Window + Frequency |
| `permutation_in_a_string.cpp` | Permutation in String | O(n) | O(1) | Sliding Window |
| `minimum_window_substring.cpp` | Minimum Window Substring | O(n) | O(n) | Sliding Window + Hash Map |
| `sliding_window_maximum.cpp` | Sliding Window Maximum | O(n) | O(k) | Monotonic Deque |
| `contains_duplicate_II.cpp` | Contains Duplicate II | O(n) | O(n) | Hash Map + Sliding Window |
| `find_k_closest_elements.cpp` | Find K Closest Elements | O(log n + k) | O(1) | Binary Search + Two Pointers |

### 📁 Stack
**Problems utilizing stack data structure for LIFO operations.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `valid_parenthesis.cpp` | Valid Parentheses | O(n) | O(n) | Stack + Hash Map |
| `evaluate_reverse_polish_notation.cpp` | Evaluate RPN | O(n) | O(n) | Stack |
| `daily_temperatures.cpp` | Daily Temperatures | O(n) | O(n) | Monotonic Stack |
| `car_fleet.py` | Car Fleet | O(n log n) | O(n) | Stack + Sorting |
| `largest_rectangle_in_histogram.cpp` | Largest Rectangle in Histogram | O(n) | O(n) | Monotonic Stack |
| `implement_stack_using_queues.cpp` | Implement Stack using Queues | O(n) | O(n) | Queue Simulation |

### 📁 Binary Search
**Problems using binary search for efficient searching in sorted data.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `binary_search.cpp` | Binary Search | O(log n) | O(1) | Classic Binary Search |
| `search_insert_position.cpp` | Search Insert Position | O(log n) | O(1) | Binary Search |
| `search_a_2D_matrix.cpp` | Search a 2D Matrix | O(log(m×n)) | O(1) | Binary Search on Matrix |
| `koko_eating_bananas.cpp` | Koko Eating Bananas | O(n log m) | O(1) | Binary Search on Answer |
| `find_minimum_in_a_rotated_sorted_array.cpp` | Find Minimum in Rotated Sorted Array | O(log n) | O(1) | Modified Binary Search |
| `search_in_rotated_sorted_array.cpp` | Search in Rotated Sorted Array | O(log n) | O(1) | Modified Binary Search |
| `time_based_key_value_store.cpp` | Time Based Key-Value Store | O(log n) | O(n) | Binary Search + Hash Map |
| `median_of_two_sorted_arrays.cpp` | Median of Two Sorted Arrays | O(log(min(m,n))) | O(1) | Binary Search Partitioning |
| `guess_number_higher_or_lower.cpp` | Guess Number Higher or Lower | O(log n) | O(1) | Binary Search |

### 📁 Linked List
**Problems involving singly/doubly linked list operations and pointer manipulation.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `reverse_linked_list.cpp` | Reverse Linked List | O(n) | O(1) | Iterative Pointer Manipulation |
| `merge_two_sorted_lists.cpp` | Merge Two Sorted Lists | O(n+m) | O(1) | Two Pointers |
| `reorder_list.cpp` | Reorder List | O(n) | O(1) | Fast/Slow + Reverse + Merge |
| `remove_nth_node_from_end_of_list.cpp` | Remove Nth Node From End | O(n) | O(1) | Two Pass Approach |
| `copy_list_with_random_pointer.cpp` | Copy List with Random Pointer | O(n) | O(n) | Hash Map |
| `add_two_numbers.cpp` | Add Two Numbers | O(max(m,n)) | O(max(m,n)) | Digit-by-Digit Addition |
| `find_duplicate_number.cpp` | Find the Duplicate Number | O(n) | O(1) | Floyd's Cycle Detection |
| `lru_cache.cpp` | LRU Cache | O(n) | O(n) | Hash Map + Frequency |
| `merge_k_sorted_lists.cpp` | Merge k Sorted Lists | O(n log k) | O(1) | Divide and Conquer |
| `reverse_nodes_in_k_group.cpp` | Reverse Nodes in k-Group | O(n) | O(1) | Group Reversal |
| `middle_of_the_linked_list.cpp` | Middle of the Linked List | O(n) | O(1) | Fast/Slow Pointers |
| `remove_duplicates_from_sorted_list.cpp` | Remove Duplicates from Sorted List | O(n) | O(1) | Single Pass |
| `reverse_linked_list_II.cpp` | Reverse Linked List II | O(n) | O(1) | Pointer Manipulation |
| `design_circular_queue.cpp` | Design Circular Queue | O(1) | O(k) | Circular Linked List |

### 📁 Trees
**Problems involving tree data structures and traversal algorithms.**

| File | Problem | Time | Space | Key Concept |
|------|---------|------|-------|-------------|
| `BST.cpp` | Binary Search Tree Implementation | O(log n) avg | O(log n) | BST Operations + Traversals |

---

## 🚀 Key Features

### 📊 **Comprehensive Analysis**
Each solution includes:
- **Time Complexity**: Worst-case analysis with Big-O notation
- **Space Complexity**: Memory usage analysis
- **LeetCode Stats**: Runtime performance and memory usage percentiles

### 🎯 **Multiple Approaches**
Many problems include multiple solution approaches:
- **Brute Force** → **Optimized** solutions
- **Different algorithmic paradigms** (e.g., iterative vs recursive)
- **Space-time tradeoffs** explained

### 📝 **Detailed Documentation**
- **Problem descriptions** with examples
- **Algorithmic approach** explanations
- **Key insights** and **edge cases**
- **Step-by-step walkthroughs**

### 🏆 **Performance Focused**
- Solutions optimized for **interview scenarios**
- **LeetCode submission statistics** included
- **Best practices** and **clean code** standards

---

## 🎯 How to Use This Repository

### **For Learning:**
1. **Read the problem description** and try solving it yourself first
2. **Review the approach section** to understand the algorithmic strategy
3. **Study the implementation** with detailed comments
4. **Analyze the complexity** to understand efficiency

### **For Interview Prep:**
1. **Focus on patterns** within each category
2. **Practice similar problems** to reinforce concepts
3. **Time yourself** and compare with provided stats
4. **Master multiple approaches** for flexibility

### **For Reference:**
1. **Quick lookup** of solution patterns
2. **Copy-paste** optimized implementations
3. **Complexity cheatsheet** for analysis
4. **Best practices** examples

---

## 🔧 Additional Files

- **`automate_leetcode_excel.py`**: Python script for automated analysis and Excel export of solution statistics using Gemini AI

---

## Contributing

Feel free to suggest improvements, optimizations, or additional approaches! This repository is continuously evolving to provide the best learning resource for coding interviews.



> **Note**: This repository follows the **NeetCode 150** series structure, making it an excellent companion for systematic interview preparation. All solutions are tested and optimized for coding interview scenarios.
