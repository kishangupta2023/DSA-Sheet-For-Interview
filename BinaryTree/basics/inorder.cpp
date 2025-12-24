// Inorder Traversal in binary tree 
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Example 1:

// Input: root = [1,null,2,3]

// Output: [1,3,2]

#include<bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
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
    void inorder(TreeNode* node,vector<int>&ans){
        if(node == NULL) return;
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }


    // iterative way for inorder traversal 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
    //tc->0(n)
    // sc->0(n)
};