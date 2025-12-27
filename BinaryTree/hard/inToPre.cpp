// Construct a binary tree from Inorder and preOrder traversal given
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
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

class Solution{
public: 
    TreeNode* buildTrees(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mpp[node->val];
        int numsLen = inRoot-inStart;
        node->left = buildTrees(preorder,preStart+1,preStart+numsLen,inorder,inStart,inRoot-1,mpp); 
        node->right = buildTrees(preorder,preStart+numsLen+1,preEnd,inorder,inRoot+1,inEnd,mpp); 
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTrees(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
    // tc-> 0(N)
    // sc -> 0(N)
};
