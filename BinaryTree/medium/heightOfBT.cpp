// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
// level wise way bfs 
    int maxDepth(TreeNode* root) {
        int height = 1;
        queue<TreeNode*>st;
        if(root == NULL) return 0;
        st.push(root);
        while(!st.empty()){
            int size = st.size();
            for(int i=0;i<size;i++){
                TreeNode* node = st.front();
                st.pop();
                if(node->left != NULL) st.push(node->left);
                if(node->right !=NULL) st.push(node->right);
            }
            if(st.size() != 0) height++;
        }
        return height;
    }
    // sc -> 0(N)

    // Recursive solution
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+max(lh,rh);
    }
    // no extra space 
    // only recursive stack space used 
    // sc->0(height) in worst case 0(n) 
};