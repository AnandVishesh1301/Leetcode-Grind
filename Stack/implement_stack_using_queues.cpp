// 225. Implement Stack using Queues
// ---------------------------------------------------------
// Problem:
// Implement a LIFO (Last-In-First-Out) stack using **only** standard
// operations of queues (push to back, pop from front, peek, size, isEmpty).
// Support the usual stack operations: push, pop, top, and empty.
//
// Approach: Two Queues 
// ---------------------------------------------------------
// - We use two queues: `q1` (main), `q2` (temporary).
// - For `push(x)`:
//     • Simply push x to `q1` (standard queue operation).
//
// - For `pop()`:
//     1. Transfer all elements from `q1` to `q2` except the last one.
//     2. Pop and store the last element (which is the top of the stack).
//     3. Swap `q1` and `q2` so that `q1` is ready for future ops.
//
// - For `top()`:
//     • Directly return `q1.back()`, since we maintain push order.
//
// - For `empty()`:
//     • Return `q1.empty()` directly.
//
// ✔ Why this works:
//   - By ensuring that the most recently pushed element remains at the end
//     of the queue, we simulate LIFO behavior using FIFO operations.
//   - Pop becomes O(n), but push is O(1).
//
// - Time Complexity:
//     • push(): O(1)
//     • pop(): O(n)
//     • top(): O(1)
//     • empty(): O(1)
// - Space Complexity: O(n) for storing elements across both queues
//
// Example:
//   push(1) → q1: [1]
//   push(2) → q1: [1,2]
//   pop() → transfer [1] to q2, pop 2 → q1 becomes [1] after swap
//
// Time Stats (from LeetCode submission):
//   Runtime      : 0 ms
//   Beats        : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 9.58 MB
//   Beats        : 18.55 % of C++ users
// ---------------------------------------------------------

// Solution:
class MyStack {
    std::queue<int> q1;
    std::queue<int> q2;

public:
    MyStack() = default;

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        // move everything except the last element to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int lastElement = q1.front();   // this is the “top” of the stack
        q1.pop();                       // remove it
        q1.swap(q2);                    // make q1 the main queue again
        return lastElement;
    }

    int top() {
        return q1.back();               // back() is the most-recent push
    }

    bool empty() {
        return q1.empty();
    }
};
