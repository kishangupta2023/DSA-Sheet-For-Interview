// // Largest Bst
// You're given a binary tree. Your task is to find the size of the largest subtree within this binary tree that also satisfies the properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes it contains.

// Note: A subtree of the binary tree is considered a BST if for every node in that subtree, the left child is less than the node, and the right child is greater than the node, without any duplicate values in the subtree.

// Examples :

// Input: root = [5, 2, 4, 1, 3]
// Root-to-leaf-path-sum-equal-to-a-given-number-copy
// Output: 3
// Explanation:The following sub-tree is a BST of size 3

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class NodeValue{
public:
    int minNode;
    int maxNode;
    int maxSize;
    NodeValue(int minNode,int maxNode,int maxSize){
        this->minNode= minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
  public:
    NodeValue largestBstSubTree(Node* root){
        if(!root){
            return NodeValue(INT_MAX,INT_MIN,0);
        }
        auto left =largestBstSubTree(root->left);
        auto right=largestBstSubTree(root->right);
        if(root->data < right.minNode && root->data > left.maxNode){
            return NodeValue(min(left.minNode,root->data),max(right.maxNode,root->data),1+left.maxSize+right.maxSize);
        }
        else return NodeValue(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
    }

    int largestBst(Node *root) {
        // Your code here
        return largestBstSubTree(root).maxSize;
    }
};