// 111. Minimum Depth of Binary Tree
// ---------------------------------------------------------
// Problem:
// Given a binary tree, return its minimum depth—the shortest path
// (in number of nodes) from the root to the nearest leaf node.
// A leaf is defined as a node with no children.
//
// ✅ Approach: Recursive DFS with Child-Existence Handling
// ---------------------------------------------------------
// - Base case: An empty node has depth 0.
// - If a node has **both** children, its minimum depth is:
//     1 + min(minDepth(left), minDepth(right))
// - If **one** child is missing, you must only consider the subtree that exists.
//   This ensures you don’t count a non‐existent path as zero.
//
//   Pseudocode:
//     if root is null → return 0
//     if both children exist:
//         leftD  = minDepth(left)
//         rightD = minDepth(right)
//     else if only left exists:
//         leftD  = minDepth(left), rightD = ∞
//     else if only right exists:
//         leftD  = ∞, rightD = minDepth(right)
//     return 1 + min(leftD, rightD)
//
// 🔁 Time Complexity : O(N) — each node visited once  
// 💾 Space Complexity: O(H) — recursion stack, H = height of tree  
//
// LeetCode Stats:
// Runtime     : 7 ms    (Beats 20.55%)  
// Memory Usage: 146.70 MB (Beats 88.87%)  
// ---------------------------------------------------------


class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) 
            return 0;                       // Empty tree has depth 0

        // Initialize both depths to "infinite" so missing child isn't chosen
        int leftD  = INT_MAX;
        int rightD = INT_MAX;

        if (root->left && root->right) {
            // Both children exist: take the minimum of both subtrees
            leftD  = minDepth(root->left);
            rightD = minDepth(root->right);
        }
        else if (!root->right) {
            // Only left subtree exists
            leftD = minDepth(root->left);
        }
        else {
            // Only right subtree exists
            rightD = minDepth(root->right);
        }

        // Current depth is one more than the smaller valid subtree depth
        return 1 + min(leftD, rightD);
    }
};
