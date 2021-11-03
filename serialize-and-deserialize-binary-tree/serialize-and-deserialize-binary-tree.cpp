/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(ostringstream &ans, TreeNode* root)
    {
        if(!root)
        {
            ans << "$ ";
            return;
        }
        
        ans << root->val<<' ';
        preorder(ans, root->left);
        preorder(ans, root->right);
    }
    
    TreeNode* buildtree(istringstream &s){
      
        string word;
        s >> word;
        if(word == "$")
        {
            return NULL;
        }
        cout<<word<<" ";
        TreeNode *root = new TreeNode(stoi(word));
        root->left = buildtree(s);
        
        root->right = buildtree(s);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream s;
        preorder(s,root);
        return s.str();  
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // if(data.size() == 0)
        //     return NULL;
       istringstream s (data);

       return buildtree(s);
        
        return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));