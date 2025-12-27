// burning tree 
// Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

// Note: The tree contains unique values.

// Examples : 

// Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
// Output: 3
// Explanation: Initially 2 is set to fire at 0 sec 
// At 1 sec: Nodes 4, 5, 1 catches fire.
// At 2 sec: Node 3 catches fire.
// At 3 sec: Nodes 6, 7 catches fire.
// It takes 3s to burn the complete tree.

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
    void findParent(Node* root,unordered_map<Node*,Node*>&parent,Node*& tar,int target){
        if(root == NULL) return;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            if(node->data == target) tar = node;
            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    int minTime(Node* root, int target) {
        // code here
        Node* tar = NULL;
        unordered_map<Node*,Node*>parent;
        findParent(root,parent,tar,target);
        unordered_map<Node*,bool>visited;
        int minTime = 0;
        queue<Node*>q;
        q.push(tar);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                visited[node] = true;
                if(node->left && visited[node->left]== false){
                    q.push(node->left);
                }
                if(node->right && visited[node->right] == false){
                    q.push(node->right);
                }
                Node* par = parent[node];
                if(par != NULL && visited[par] == false){
                    q.push(par);
                } 
            }
            if(!q.empty()){
               minTime++;
            }
        }
        return minTime;
    }
    // tc -> 0(n)+0(n)+0(n)
    // sc -0(2n)
    
};