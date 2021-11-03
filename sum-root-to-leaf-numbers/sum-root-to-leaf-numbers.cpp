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
    int res=0;
    
   void helper(TreeNode* root, int sum)
   {
       if(!root)
            return;
       
       sum = sum*10 + root->val;
       if(root->left == NULL && root->right == NULL){
           res += sum;
           return;
       }
         helper(root->left, sum);
         helper(root->right, sum);
        
   }
        
    int sumNumbers(TreeNode* root) {
        
        if(!root)
            return 0;
        int sum = 0;
        helper(root, sum);
        return res;   
    }
};