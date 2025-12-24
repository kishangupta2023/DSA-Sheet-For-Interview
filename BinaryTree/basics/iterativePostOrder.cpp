// Iterative PostOrder Traversal Using 2 stack

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
 
class Solution{
    vector<int> postorder(TreeNode* root){
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        if(root == NULL) return ans;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left !=NULL) st1.push(node->left);
            if(node->right != NULL) st1.push(node->right);
        }
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
    // tc -> 0(N)
    // sc -> 0(2N)
   
    // Iterative PostOrder Traversal Using 1 stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }else{
                    curr = temp;
                }
            }
        }

    }
};