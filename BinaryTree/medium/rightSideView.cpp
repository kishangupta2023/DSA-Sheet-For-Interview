// Binary Tree Right Side View
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
// Example 1:
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int level = it.second;
            if(mpp.find(level) == mpp.end()){
                mpp.insert({level,node->val});
            }
            if(node->right != NULL){
                q.push({node->right,level+1});
            }
            if(node->left != NULL){
                q.push({node->left,level+1});
            }
        }
        for(auto it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
