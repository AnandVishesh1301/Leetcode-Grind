/**
 * 100: Same Tree
 *
 * Approach:
 * This solution uses **DFS traversal (preorder)** to serialize both binary trees into arrays and then compares the arrays.
 * If the arrays are identical in values and structure (including NULL positions), the trees are considered the same.
 *
 * Key Trick:
 * - When encountering a `nullptr` (null child), we **append LLONG_MAX** (a large sentinel value) to the array.
 * - This is necessary because actual node values could include `0` or even large positive/negative values.
 *   Using LLONG_MAX ensures it can never be confused with a real node value.
 *
 * Why not just compare p and q recursively?
 * - This version serializes both trees and compares their structure + values in one go, which is useful in debugging
 *   or converting tree structure into another format.
 *
 * Time Complexity:  O(N) — where N is the number of nodes (each node is visited once)
 * Space Complexity: O(N) — additional space used to store serialized arrays for both trees
 * 
    Stats:
 * ✅ Runtime: 0 ms, beats 100%
 * ✅ Memory: 13.12 MB, beats 14.70%
 */

class Solution {
private:
    // Recursive DFS to flatten tree into an array using preorder traversal
    // We use long long to handle sentinel value LLONG_MAX safely
    void dfs(TreeNode* root, vector<long long>& arr) {
        if (!root) {
            arr.push_back(LLONG_MAX);     // Use large sentinel to mark NULLs
            return;
        }
        arr.push_back(root->val);         // Store node value
        dfs(root->left, arr);             // Recur on left child
        dfs(root->right, arr);            // Recur on right child
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<long long> tree1;
        vector<long long> tree2;

        dfs(p, tree1);                    // Serialize first tree
        dfs(q, tree2);                    // Serialize second tree

        return tree1 == tree2;            // Compare serialized outputs
    }
};
