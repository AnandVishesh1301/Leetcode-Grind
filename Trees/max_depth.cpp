// 104. Maximum Depth of Binary Tree
// ---------------------------------------------------------
// Problem:
// Given the root of a binary tree, return its maximum depth.
// The maximum depth is the number of nodes along the longest path
// from the root down to the farthest leaf.
//
// ✅ Approach: Recursive DFS
// ---------------------------------------------------------
// - Use depth-first search to compute the depth of each subtree.
// - Base case: An empty node has depth 0.
// - Recurse on left and right children to get their depths:
//     leftDepth  = maxDepth(root->left)
//     rightDepth = maxDepth(root->right)
// - The depth at the current node is 1 + max(leftDepth, rightDepth).
//
// Time Complexity : O(N) – each node visited once  
// Space Complexity: O(H) – recursion stack depth, H = height of tree  
//
// Runtime     : 0 ms   (Beats 100%)  
// Memory Usage: 19.00 MB (Beats 45.88%)  
// ---------------------------------------------------------

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) 
            return 0;                          // Base case: empty tree

        // Compute depths of left and right subtrees
        int leftDepth  = maxDepth(root->left);  
        int rightDepth = maxDepth(root->right);

        // Current node adds 1 to the greater of the two depths
        return 1 + max(leftDepth, rightDepth);
    }
};

/*
Sample Call Stack for root = [3,9,20,null,null,15,7]:

maxDepth(3)
 ├─ maxDepth(9)
 │    ├─ maxDepth(nullptr) → 0
 │    └─ maxDepth(nullptr) → 0
 │    → returns 1 + max(0,0) = 1
 └─ maxDepth(20)
      ├─ maxDepth(15)
      │    ├─ maxDepth(nullptr) → 0
      │    └─ maxDepth(nullptr) → 0
      │    → returns 1 + max(0,0) = 1
      └─ maxDepth(7)
           ├─ maxDepth(nullptr) → 0
           └─ maxDepth(nullptr) → 0
           → returns 1 + max(0,0) = 1
      → returns 1 + max(1,1) = 2
→ returns 1 + max(1,2) = 3
*/
