// Postorder Traversal in binary tree 
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
// Example 1:

// Input: root = [1,null,2,3]

// Output: [3,2,1]

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
    void postorder(TreeNode* node,vector<int>&ans){
        if(node == NULL) return;
        postorder(node->left,ans);
        postorder(node->right,ans);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorder(root,ans);
        return ans;
    }
};