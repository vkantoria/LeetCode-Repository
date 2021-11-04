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
        int res = INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l = solve(root->left);
        int r = solve(root->right);
        
        //if node's only one subtree included in path OR node only own included in path
        
        int temp = max((max(l,r)+(root->val)), (root->val));
        
        //if this node's both child is in max sum path
        int tempans = max(temp, (l + r + (root->val)));
        res = max(res, tempans);
        
        return temp;
    }
    
    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
};