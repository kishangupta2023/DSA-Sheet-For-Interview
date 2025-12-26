// // Print Root to Node Path in Binary Tree
// Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5, N, N]
// ex-3
// Output: [[1, 2, 4], [1, 2, 5], [1, 3]]

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }
    void getPath(Node* node,vector<int>&path,vector<vector<int>>&ans){
        if(node == NULL) return;
        path.push_back(node->data);
        if(isLeaf(node)){
            ans.push_back(path);
        }
        else{
            getPath(node->left,path,ans);
            getPath(node->right,path,ans);
        }
        path.pop_back();
    }
    vector<vector<int>> getAllPath(Node* root){
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        vector<int>path;
        getPath(root,path,ans);
        return ans;
    }
};