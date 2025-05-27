// Daily Temperatures
// You are given an array `temperatures[]`, where `temperatures[i]` represents the temperature on day `i`.
// Return an array `result[]` such that `result[i]` is the number of days you have to wait after day `i`
// to get a warmer temperature. If no such future day exists, `result[i] = 0`.
//
// Example 1:
//   Input : temperatures = [73,74,75,71,69,72,76,73]
//   Output: [1,1,4,2,1,1,0,0]
//
// Example 2:
//   Input : temperatures = [30,40,50,60]
//   Output: [1,1,1,0]
//
// Example 3:
//   Input : temperatures = [30,60,90]
//   Output: [1,1,0]
//
// Approach:
// - Use a **monotonic decreasing stack** to keep track of the temperatures.
// - Stack stores **pairs**: (temperature, index).
// - For each day `i`:
//     - While the current temperature is **greater** than the temperature at the top of the stack,
//       pop the top, and calculate the number of days waited (`i - prev_index`) and store it in result.
//     - Push the current temperature and index onto the stack.
// - After processing, any day without a warmer future temperature remains 0.
//
// Time Complexity: **O(N)** — each index is pushed and popped at most once
// Space Complexity: **O(N)** — for the stack and result array
//
// Time Stats (from LeetCode submission):
//   Runtime : 30 ms  
//   Beats   : 30.82 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 111.71 MB
//   Beats        : 14.32 % of C++ users


// Solution:
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);  // Default to 0 days wait
        stack<pair<int, int>> s;   // Stores (temperature, index)

        for (int i = 0; i < n; i++) {
            // While current temp is higher than the temp at top of stack
            while (!s.empty() && temperatures[i] > s.top().first) {
                auto [prevTemp, prevIndex] = s.top();
                s.pop();
                result[prevIndex] = i - prevIndex;  // Days waited for a warmer temp
            }
            s.push({temperatures[i], i});  // Push current temp with its index
        }
        return result;
    }
};

