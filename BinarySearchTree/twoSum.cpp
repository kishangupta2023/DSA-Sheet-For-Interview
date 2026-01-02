// // Two Sum IV - Input is a Bst 
// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true


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
    void findInorder(TreeNode* root,vector<int>&inorder){
        if(root == NULL) return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        findInorder(root,inorder);
        int i=0;
        int j=inorder.size()-1;
        int res = inorder[0];
        while(i < j){
            if(inorder[i] + inorder[j] == k) return true;
            if(inorder[i] + inorder[j] < k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
    // tc-> 0(2n)
    // sc ->0(N)

    // my solution
    
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>st1,st2;
        TreeNode* l = root;
        TreeNode* r = root;
        while(l || !st1.empty() || !st2.empty()){
            while(l){
                st1.push(l);
                l = l->left;
            }
            while(r){
                st2.push(r);
                r =r->right;
            }
            if(st1.top() == st2.top()) return false;
            if(st1.top()->val + st2.top()->val == k) return true;
            if(st1.top()->val + st2.top()->val < k){
                TreeNode* dummy = st1.top();
                st1.pop();
                l = dummy->right;
            }else{
                TreeNode* dummy = st2.top();
                st2.pop();
                r = dummy->left;
            }
        }
        return false;
    }
    // tc->0(n)
    // sc->0(h)

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        stack<TreeNode*> st1, st2;
        TreeNode *l = root, *r = root;

        // initialize inorder iterator
        while (l) {
            st1.push(l);
            l = l->left;
        }

        // initialize reverse inorder iterator
        while (r) {
            st2.push(r);
            r = r->right;
        }

        while (!st1.empty() && !st2.empty() && st1.top() != st2.top()) {
            int sum = st1.top()->val + st2.top()->val;

            if (sum == k) return true;
            else if (sum < k) {
                TreeNode* node = st1.top(); st1.pop();
                node = node->right;
                while (node) {
                    st1.push(node);
                    node = node->left;
                }
            } else {
                TreeNode* node = st2.top(); st2.pop();
                node = node->left;
                while (node) {
                    st2.push(node);
                    node = node->right;
                }
            }
        }
        return false;
    }
};