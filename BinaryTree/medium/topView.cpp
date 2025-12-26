// Top View of Binary Tree 
// You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

// Note:

// Return the nodes from the leftmost node to the rightmost node.
// If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
// Examples:
// Input: root = [1, 2, 3]
// Output: [2, 1, 3]
// Explanation: The Green colored nodes represents the top view in the below Binary tree.

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
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root == NULL) return ans;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        map<int,int>mpp;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int x = it.second;
            if(mpp.find(x) == mpp.end()){
                mpp.insert({x,node->data});
            }
            if(node->left != NULL){
                q.push({node->left,x-1});
            }
            if(node->right != NULL){
                q.push({node->right,x+1});
            }
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
    // tc -> 0(n) <- sc 
};