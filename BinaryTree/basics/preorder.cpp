// Preorder Traversal in Binary tree 
// Binary Tree represenatation 
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


// root left right 
void preorder(Node* node){
    if(node == NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}
// tc-> 0(N)
// sc -> 0(N)


int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
}