// Bottom View of Binary Tree 
// You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, 6]
    
// Output: [4, 2, 5, 3, 6]

#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int>ans;
        queue<pair<Node*,int>>q;
        if(root == NULL) return ans;
        map<int,int>mpp;
        q.push({root,0});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int x = it.second;
            if(mpp.find(x) == mpp.end()){
                mpp.insert({x,node->data});
            }
            if(mpp.find(x) != mpp.end()){
                mpp[x] = node->data;
            }
            if(node->left != NULL){
                q.push({node->left,x-1});
            }
            if(node->right != NULL){
                q.push({node->right,x+1});
            }
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};

