//  Lowest Common Ancestor of a Binary Search Tree
//  Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
// Output: 6
// Explanation: The LCA of nodes 2 and 8 is 6.

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
    bool findPath(TreeNode* root, TreeNode* p,vector<TreeNode*>&path){
        if(root == NULL) return false;
        path.push_back(root);
        if(root->val == p->val){
            return true;
        }
        if(p->val > root->val){
            if(findPath(root->right,p,path)) return true;
        }else{
            if(findPath(root->left,p,path)) return true;
        }
        path.pop_back(); 
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1;
        vector<TreeNode*>path2;
        findPath(root,p,path1);
        findPath(root,q,path2);
        TreeNode* res= NULL;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i] == path2[i]) res= path1[i];
        }
        return res;
    }
    // tc-> 0(N+2H)
    // sc-> 0(2N) + recursive stack space


    // optimal Solution 
    TreeNode* findPath(TreeNode* root, TreeNode* p,TreeNode* q){
        if(root == NULL) return NULL;
        if((root->val >= p->val && root->val <= q->val) || (root->val <= p->val && root->val >= q->val)){
            return root;
        }
        else if(root->val > p->val && root->val > q->val){
            return findPath(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val){
            return findPath(root->right,p,q);
        }
        return NULL;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root== NULL) return NULL;
        TreeNode* res= NULL;
        res = findPath(root,p,q); 
        return res;
    }
    // tc->0(h) || o(logn)
    // sc -> 0(1)   =0(logn) no extra space only stack space
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left;
            else if (p->val > root->val && q->val > root->val)
                root = root->right;
            else
                return root;  // split point
        }
        return NULL;
    }
    // tc->0(h)
    // sc ->0(1)
};


