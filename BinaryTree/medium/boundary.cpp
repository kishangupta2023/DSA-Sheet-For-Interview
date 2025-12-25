// Given a root of a Binary Tree, return its boundary traversal in the following order:

// Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

// Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

// Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

// Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

// Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]

#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    bool isLeaf(Node* node){
        if(node->left == NULL && node->right ==NULL) return true;
        return false;
    }
    void traverseLeft(Node* root,vector<int>&res){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr= curr->left;
            else curr = curr->right;
        }
    }

    void traverseLeaf(Node* root,vector<int>&res){
        if(root == NULL) return;
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)traverseLeaf(root->left,res);
        if(root->right)traverseLeaf(root->right,res);
    }
    void traverseRight(Node* root,vector<int>&res){
        Node* curr = root->right;
        vector<int>temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr= curr->right;
            else curr = curr->left;
        }
        for(int i=(int)temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    
    vector<int> boundaryTraversal(Node* root){
        vector<int>res;
        if(root == NULL) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        traverseLeft(root,res);
        traverseLeaf(root,res);
        traverseRight(root,res);
        return res;
    }
    // tc-> 0(n)
    // sc -> 0(n)
};