// Kth smallest in bst 
// Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

// Example 1:

// Input: root = [3,1,4,null,2], k = 1
// Output: 1

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
// for kth largest just make k = n-k and return the ans 
 
class Solution {
public:
    void findInorder(TreeNode* root,vector<int>&inorder){
        if(root == NULL) return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        findInorder(root,inorder);
        int ans = inorder[k-1];
        return ans;
    }
    // tc -> 0(n) 
    // sc ->0(n)

    // optimal Solution 
    // morris traversal inorder 
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* cur = root;
        int cnt = 0;
        int ans = -1;
        while (cur != NULL) {
            if (cur->left == NULL) {
                cnt++;
                if (cnt == k) ans = cur->val;
                cur = cur->right;
            } 
            else {
                TreeNode* prev = cur->left;

                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = cur;   // create thread
                    cur = cur->left;
                } 
                else {
                    prev->right = NULL;  // restore tree
                    cnt++;
                    if (cnt == k) ans = cur->val;
                    cur = cur->right;
                }
            }
        }
        return ans; // k was invalid
    }
    // tc -> 0(N)
    // sc-> 0(1)

};