//  Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]


 
#include<bits/stdc++.h>
using namespace std;
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
    TreeNode* buildTrees(vector<int>& postorder,int postStart,int postEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(postStart > postEnd || inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[node->val];
        int numsLen = inRoot-inStart;
        node->left = buildTrees(postorder,postStart,postStart+numsLen-1,inorder,inStart,inRoot-1,mpp); 
        node->right = buildTrees(postorder,postStart+numsLen,postEnd-1,inorder,inRoot+1,inEnd,mpp); 
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTrees(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};