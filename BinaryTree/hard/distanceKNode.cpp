// // Print all nodes at a distance k from some Node p 
// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution{
public:
      void findParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parents){
        if(root == NULL) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                parents[node->left] = node;
                findParent(node->left,parents);
            }
            if(node->right){
                parents[node->right] = node;
                findParent(node->right,parents);
            }
        }
      }

      vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // for marking all the nodes parent if exists 
        unordered_map<TreeNode*,TreeNode*>parents;
        findParent(root,parents);
        // for checking whether the node is already visited in the q 
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                visited[node] = true;
                if(node->left && visited[node->left] == false){
                    q.push(node->left);
                }
                if(node->right && visited[node->right] == false){
                    q.push(node->right);
                }
                TreeNode* par = parents[node];
                if(par != NULL && visited[par] == false){
                    q.push(par);
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    // tc -> 0(n)+0(n)+0(n)
    // sc -> 0(n) + 0(n) overall 0(n)
};