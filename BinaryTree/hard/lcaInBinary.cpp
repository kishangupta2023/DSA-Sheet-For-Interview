// // Lowest Common Ancestor of binary tree
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
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
    bool findPath(TreeNode* root,TreeNode* p,vector<TreeNode*>&temp){
        if(root == NULL) return false;
        temp.push_back(root);
        if(root == p){
            return true;
        }
        if(findPath(root->left,p,temp) || findPath(root->right,p,temp)){
            return true;
        }
        temp.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        vector<TreeNode*>temp1;
        vector<TreeNode*>temp2;
        findPath(root,p,temp1);
        findPath(root,q,temp2);
        int size = min(temp1.size(),temp2.size());
        TreeNode* common = NULL;
        for(int i=0;i<size;i++){
            if(temp1[i] == temp2[i]){
                common = temp1[i];
            }else{
                break;
            }
        }
        return common;
    }
    // tc -> 0(2N)
    // sc ->0(2H)

    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    // tc -> 0(N)
    // sc -> 0(N) recursive stack space 
};