// Diameter of Binary Tree 
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
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
    int height(TreeNode* node){
        if(node == NULL) return 0;
        int left = height(node->left);
        int right = height(node->right);
        return 1+max(left,right);
    }
    int diameter(TreeNode* root){
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return (lh+rh);
    }
    int maxi = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        maxi = max(maxi,(lh+rh));
        if(root->left != NULL)diameterOfBinaryTree(root->left);
        if(root->right != NULL) diameterOfBinaryTree(root->right);
        return maxi;
    }
    // tc-> 0(N*N)


    // optimal solution
    int height(TreeNode* node,int& maxi){
        if(node == NULL) return 0;
        int left = height(node->left,maxi);
        int right = height(node->right,maxi);
        maxi = max(maxi,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
    // tc-> 0(N)



};