// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */


    // Function to return the diameter of a Binary Tree.
    /*
    
   int diameterOpt(struct Node* root, int* height)
{
    
    int lh = 0, rh = 0;
    
    int ldiameter = 0,rdiameter = 0;
    
    if(root == NULL)
    {
        return 0;
    }
    ldiameter = diameterOpt(root->left,&lh);
    rdiameter = diameterOpt(root->right,&rh);
    
    *height = max(lh,rh) + 1;
    
    return max(lh+rh+1, max(ldiameter,rdiameter));
}

*/

class Solution {
  public:

pair<int,int> isHelperFunc(Node* root)
{
    if(!root)
       return {0,0};
    
    pair<int, int> l = isHelperFunc(root->left);
    pair<int, int> r = isHelperFunc(root->right);
    
    return make_pair(max(l.second+r.second+1, max(l.first, r.first)), max(l.second, r.second)+1);
}

int diameter(struct Node* root) {
    // code here
   // int height = 0;
    
   // return diameterOpt(root,&height);
   return isHelperFunc(root).first;
}
};
// { Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends