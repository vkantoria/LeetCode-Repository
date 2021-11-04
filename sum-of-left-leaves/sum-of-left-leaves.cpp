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
    int sum = 0;
    
    void helper(TreeNode* root,int s)
    {
        if(!root)
            return;
        if(s == 0 && (!root->left && !root->right))
        {
           sum += root->val;
            return;
        }
        helper(root->left,0);
        helper(root->right,1);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return 0;
        helper(root,0);
        return sum;
        
    }
};