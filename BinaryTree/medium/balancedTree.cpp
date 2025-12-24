// Given a binary tree, determine if it is height-balanced.
// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

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
    int height(TreeNode* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left, right);
    }

    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int lh =height(root->left);
        int rh =height(root->right);
        if(abs(lh-rh) > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right) return false;
        return true;
    }
    // tc -> 0(N*N)


    // optimal approach 
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int lh =height(root->left);
        int rh =height(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh) >1) return -1;
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
    // tc ->0(N)
    // sc ->0(N)

};