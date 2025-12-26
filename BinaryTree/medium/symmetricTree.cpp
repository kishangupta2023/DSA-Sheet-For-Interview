//  Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
// Example 1:
// Input: root = [1,2,2,3,4,4,3]
// Output: true


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
    bool Traverse(TreeNode* r1,TreeNode* r2){
        if(r1 == NULL && r2 != NULL) return false;
        if(r1 != NULL && r2 == NULL) return false;
        if(r1 == NULL && r2 == NULL) return true;
        if(r1->val != r2->val){
            return false;
        }
        bool left=  Traverse(r1->left,r2->right);
        bool right= Traverse(r1->right,r2->left);
        return (left && right);
        
    }
    bool isSymmetric(TreeNode* root){
        if(root == NULL) return true;
        return Traverse(root->left,root->right);
    }
};