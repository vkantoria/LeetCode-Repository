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
    
    TreeNode* maketree(vector<int>& inorder, vector<int>& postorder, int instart, int inend, int poststart, int postend)
    {
        if(postend>poststart)
            return NULL;
        int i;
        TreeNode* root = new TreeNode(postorder[poststart]);
        
        for(i=instart;i<=inend;i++)
        {
            if(inorder[i] == root->val)
            {
                break;
            }
        }
        root->right = maketree(inorder, postorder, i+1, inend, poststart-1, poststart - (inend-i) );
        root->left = maketree(inorder,postorder, instart,i-1,poststart - (inend-i) -1,  postend);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int m = inorder.size();
        int instart = 0, inend = m-1;
        int poststart = m-1, postend = 0;
        
       return maketree(inorder, postorder, instart, inend, poststart, postend);
        
    }
};