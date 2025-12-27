// Children Sum in a Binary Tree
// Given the root of a binary tree, determine whether the tree satisfies the Children Sum Property. In this property, each non-leaf node must have a value equal to the sum of its left and right children's values. A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.
// Return true if every node in the tree satisfies this condition, otherwise return false.

// Examples:

// Input: root = [35, 20, 15, 15, 5, 10, 5]

// Output: True

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
    bool isLeaf(Node* root){
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }
    bool checkSum(Node* root){
        if(root == NULL || isLeaf(root)) return true;
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        if(root->data != sum) return false;
        bool left = checkSum(root->left);
        bool right = checkSum(root->right);
        if(left && right) return true;
        return false;
    }
    bool isSumProperty(Node *root) {
        // code here
        return checkSum(root);
    }
    // tc -> 0(N)
    
};