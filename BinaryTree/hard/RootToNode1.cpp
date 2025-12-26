// Root to node path in Binary Tree 
// you are given the leaf node return the possible path from root to that leaf

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
      bool getpath(TreeNode* root,vector<int>&ans,int B){
        if(!root) return false;
        ans.push_back(root->val);
        if(root->val == B) return true;
        if(getpath(root->left,ans,B) || getpath(root->right,ans,B)) return true;
        ans.pop_back();
        return false;
      }
      vector<int>RootToNode(TreeNode* A,int B){
        vector<int>ans;
        if(A== NULL) return ans;
        getpath(A,ans,B);
        return ans;
      }
      // tc -> 0(N)
      // sc -> 0(H) height of the tree 
      
    
};