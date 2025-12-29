
// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

// Examples:

// Input:
// n = 7               2
//                      \
//                       81
//                     /     \
//                  42       87
//                    \       \
//                     66      90
//                    /
//                  45
// x = 87
// Output: 87
// Explanation: 87 is present in tree so floor will be 87.


#include<Bits/stdc++.h>
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

class Solution {
  public:
    int floor(Node* root, int x) {
        // code here
        int ans = -1;
        while(root != NULL){
            if(root->data <= x){
                ans = root->data;
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return ans;
    }
};