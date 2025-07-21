// 226. Invert Binary Tree
// ---------------------------------------------------------
// Problem:
// Given the root of a binary tree, invert it so that the left and right
// children of all nodes are swapped.
//
// ---------------------------------------------------------
// ✅ Approach: DFS (Pre-order) – Recursive
// ---------------------------------------------------------
// - This is a recursive DFS solution that swaps the left and right children
//   of each node starting from the root (pre-order traversal).
// - For each node, we:
//    1. Swap its left and right children.
//    2. Recursively invert the left subtree.
//    3. Recursively invert the right subtree.
//
// 🔁 Time Complexity  : O(N)  – every node is visited once
// 💾 Space Complexity : O(H)  – recursion stack where H = height of tree
//                       → O(log N) for balanced, O(N) for skewed trees
//
// Alternate Approach:
// - BFS Iterative (using a Queue):
//     Traverse level-by-level and swap children at each node.
//     Space Complexity becomes O(W), where W is the max width of the tree.
//
// ✅ Leetcode Stats:
// Runtime: 0 ms (Beats 100%)
// Memory : 12.36 MB (Beats 85.99%)
// ---------------------------------------------------------

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; // Base Case: empty node

        // Swapping the children of the current node
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursive calls for the Left and Right Subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root; // Return the root of the inverted tree
    }
};


// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]
// Recursion Call Stack Trace for the above input:
// ┌─────────────────────────────────────────────┐
// │ Frame 1: invertTree(4)                     
// │  • Before swap:  left=2     right=7        
// │  • After  swap:  left=7     right=2        
// │                                             
// │  ├─▶ Frame 2: invertTree(7)                
// │  │    • Before swap: left=6   right=9       
// │  │    • After  swap:  left=9   right=6      
// │  │                                           
// │  │    ├─▶ Frame 3: invertTree(9)            
// │  │    │      • 9 is a leaf (both children null)
// │  │    │      • swap does nothing             
// │  │    │                                           
// │  │    │      ├─▶ invertTree(nullptr) → return  
// │  │    │      └─▶ invertTree(nullptr) → return  
// │  │    └─ returns to Frame 2                   
// │  │                                           
// │  │    └─▶ Frame 4: invertTree(6)             
// │  │         • 6 is a leaf → swap no-op        
// │  │         ├─▶ invertTree(nullptr)            
// │  │         └─▶ invertTree(nullptr)            
// │  │    └─ returns to Frame 2                   
// │  └─ returns to Frame 1                        
// │                                            
// │  └─▶ Frame 5: invertTree(2)                
// │       • Before swap: left=1   right=3       
// │       • After  swap:  left=3   right=1      
// │                                               
// │       ├─▶ Frame 6: invertTree(3)            
// │       │    • 3 is a leaf                     
// │       │    ├─▶ invertTree(nullptr)          
// │       │    └─▶ invertTree(nullptr)          
// │       └─ returns to Frame 5                 
// │                                              
// │       └─▶ Frame 7: invertTree(1)            
// │            • 1 is a leaf                     
// │            ├─▶ invertTree(nullptr)          
// │            └─▶ invertTree(nullptr)          
// │       └─ returns to Frame 5                 
// │  └─ returns to Frame 1                        
// └─ return final root (4)                        
