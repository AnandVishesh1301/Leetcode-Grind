/**
 * 94: Binary Tree Inorder Traversal
 * ------------------------------------------
 * ✅ Runtime: 0 ms, beats 100%
 * ✅ Memory: 10.75 MB, beats 87.02%
 *
 * Approach:
 * This is a standard recursive Depth-First Search (DFS) approach to perform **inorder traversal**
 * of a binary tree. The traversal order for **inorder** is: Left ➝ Node ➝ Right.
 *
 * We use a helper function `dfs()` to recursively traverse the tree and store node values in a `result` vector.
 *
 * Why use a helper function like `dfs()`?
 * - It simplifies code readability and modularizes the traversal logic.
 * - Since the LeetCode function must return a vector, using `dfs()` allows the result to be built up cleanly.
 *
 * Time Complexity:  O(N) — where N is the number of nodes (each node is visited once).
 * Space Complexity: O(H) — recursion stack where H is the height of the tree.
 *     - Worst case: O(N) for skewed trees; Best case: O(log N) for balanced trees.
 *
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);         // Start DFS traversal from root
        return result;
    }

private:
    // Recursive DFS to perform inorder traversal (Left → Node → Right)
    void dfs(TreeNode* node, vector<int>& arr) {
        if (!node) return;         // Base case: Null node reached

        dfs(node->left, arr);      // Recur on left subtree
        arr.push_back(node->val);  // Visit current node
        dfs(node->right, arr);     // Recur on right subtree
    }
};
