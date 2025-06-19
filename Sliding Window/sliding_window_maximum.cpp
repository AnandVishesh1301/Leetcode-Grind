// 239. Sliding Window Maximum

// Problem:
// Given an integer array `nums` and a window size `k`, return a
// list of the maximums for each sliding window of size `k`.
//
// Approach: Monotonic Deque (Decreasing Order)
// ---------------------------------------------------------
// - We use a deque to store **indices** of elements in the current window.
// - The deque is maintained in **monotonic decreasing order by value** so:
//      - The front of the deque always holds the index of the maximum element.
//      - We pop from the **back** if the current value is greater (invalidates smaller elements).
//      - We pop from the **front** if the index is out of the current window (r - k).
// - Why deque?
//      - We need to **push and pop** from both ends efficiently.
//      - `push_back`: to insert current element
//      - `pop_back`: to maintain decreasing order
//      - `pop_front`: to remove outdated elements
//
// ✔ Why this works:
//   - Every element is pushed and popped at most once, ensuring O(n) time.
//   - Always get the max in constant time via the front of the deque.
//
//
// Time Complexity: O(n)
// Space Complexity: O(k)
//
// Runtime     : 26 ms  (Beats 50.18%)
// Memory Usage: 139.03 MB (Beats 82.98%)
// ---------------------------------------------------------
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;               // store indices, monotonic decreasing by value
        vector<int> output;

        for (int r = 0; r < nums.size(); ++r) {
            // Maintain decreasing deque: pop from back if current is larger
            while (!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }

            dq.push_back(r);         // push current index

            // Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= r - k){
                dq.pop_front();
            }

            // Record the max once we have a full window
            if (r >= k - 1){
                output.push_back(nums[dq.front()]);
            }
        }
        return output;
    }
};

// Approach 2: Brute Force Approach
// Time Complexity: O(n*k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> window;
        if (k == 0) return window;
        for(int i=0; i+k<=nums.size(); i++){
            int l=i;
            int r=i+k-1;
            int maxWindow = INT_MIN;
            for(int j =l; j<=r;j++){
                maxWindow = max(maxWindow, nums[j]);
            }
            window.push_back(maxWindow);
        }
        return window;
        
    }
    
};
