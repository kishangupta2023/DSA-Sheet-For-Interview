// Construct Binary Search Tree from preorder Traversal 
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
// Example 1:
// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

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
    TreeNode* buildTree(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(preorder[preStart]);
        int index = mpp[node->val];
        int numlen = index-inStart;
        node->left = buildTree(preorder,preStart+1,preStart+numlen,inorder,inStart,index-1,mpp);
        node->right = buildTree(preorder,preStart+numlen+1,preEnd,inorder,index+1,inEnd,mpp);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        inorder = preorder;
        sort(inorder.begin(),inorder.end());
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};
