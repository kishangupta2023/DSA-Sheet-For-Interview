// Merge Two Bst's 
// You are given the root of two BSTs, you have to merge this two BST and return the in-order traversal of the new BST.

// Examples: 

// Input: root1 = [3, 1, 5], root2 = [4, 2, 6]

// Output: [1, 2, 3, 4, 5, 6]
// Explanation: After merging and sorting the two BST we get [1, 2, 3, 4, 5, 6].

#include<bits/stdc++.h>
using namespace std;



class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void findInorder(Node* root,vector<int>&inorder){
        if(root == NULL) return;
        findInorder(root->left,inorder);
        inorder.push_back(root->data);
        findInorder(root->right,inorder);
    }
   vector<int> merge(Node *root1, Node *root2) {
        // code here
        vector<int>inorder1;
        vector<int>inorder2;
        findInorder(root1,inorder1);
        findInorder(root2,inorder2);
        vector<int>ans;
         int i = 0, j = 0;

        while (i < inorder1.size() && j < inorder2.size()) {
            if (inorder1[i] <= inorder2[j])
                ans.push_back(inorder1[i++]);
            else
                ans.push_back(inorder2[j++]);
        }

        while (i < inorder1.size())
            ans.push_back(inorder1[i++]);

        while (j < inorder2.size())
            ans.push_back(inorder2[j++]);
        return ans;
    } 
    // tc-> 0(n+m)
    // sc -> 0(n+m)

    // optimal without any extra space 
    vector<int> merge(Node *root1, Node *root2) {
        // code here
        stack<Node*>st1,st2;
        vector<int>ans;
        while(root1 || root2 || !st1.empty() || !st2.empty()){
            while(root1){
                st1.push(root1);
                root1 = root1->left;
            }
            while(root2){
                st2.push(root2);
                root2 = root2->left;
            }
            if(st2.empty() || (!st1.empty() && st1.top()->data <= st2.top()->data)){
                Node* node = st1.top();
                st1.pop();
                ans.push_back(node->data);
                root1 = node->right;
            }
            else{
                Node* node = st2.top();
                st2.pop();
                ans.push_back(node->data);
                root2 = node->right;
            }
        }
        return ans;
    } 
    // tc -> 0(n+m)
    // sc -> 0(1)

    
};