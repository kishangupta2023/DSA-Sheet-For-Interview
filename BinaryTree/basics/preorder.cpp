// Preorder Traversal in Binary tree 
// Binary Tree represenatation 
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// root left right 
void preorder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
// tc-> 0(N)
// sc -> 0(N)


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
}


// iterative preorder Traversal 

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root == NULL) return ans;
        st.push(root);
        while(!st.empty()){
            int size = st.size();
            for(int i=0;i<size;i++){
                TreeNode* node = st.top();
                st.pop();
                if(node->right != NULL) st.push(node->right);
                if(node->left != NULL) st.push(node->left);
                ans.push_back(node->val);
            }
        }
        return ans;
    }
    // tc -> 0(n)
    // sc -> 0(n)
};