// Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

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
    void findBst(TreeNode* root,vector<int>&inorder){
        if(root == NULL) return;
        findBst(root->left,inorder);
        inorder.push_back(root->val);
        findBst(root->right,inorder);
    }
    bool isValidBST(TreeNode* root){
        if(root == NULL) return true;
        vector<int>inorder;
        findBst(root,inorder);
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i] >= inorder[i+1]) return false;
        }
        return true;
    }
    // tc->0(2n)
    // sc->(n)

    bool isvalidBST(TreeNode* root,long long minVal,long long maxVal){
        if(root == NULL) return true;
        if(root->val >= maxVal || root->val <= minVal) return false;
        return isvalidBST(root->left,minVal,root->val) && isvalidBST(root->right,root->val,maxVal);
    }
    bool isValidBST(TreeNode* root){
        return isvalidBST(root,LLONG_MIN,LLONG_MAX);
    }
};