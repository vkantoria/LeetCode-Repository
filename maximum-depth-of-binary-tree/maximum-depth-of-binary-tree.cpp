/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        
//         if(!root)
//         {
//             return 0;
//         }
//          int righth=1 ;
//          int lefth=1;
        
        
//         if(root->left)
//         {
//              lefth = 1 + maxDepth(root->left);
//         }
        
//         if(root->right)
//         {
//              righth = 1 + maxDepth(root->right);
//         }
        
//         if(lefth<righth)
//         {
//             return righth;
//         }
//         else 
//             return lefth;
        if(!root)
              return 0;
        
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l,r)+1;
    }
};