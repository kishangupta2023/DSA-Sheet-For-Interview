// Preorder Inorder and postorder traversal in a single code 

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
    void preInPostTraversal(TreeNode* root){
        vector<int>pre,in,post;
        stack<pair<TreeNode*,int>>st;
        if(root == NULL) return;
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it.second == 1){
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);
                if(it.first->left != NULL) st.push({it.first->left,1});
            }
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);
            }
            else{
                post.push_back(it.first->val);
            }
        }
    }
};