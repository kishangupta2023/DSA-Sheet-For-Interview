#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution {
    public: 
    vector<int> bfsOfGraph(int V,vector<int> adj[]){
        int vis[V] = {0};
        vis[0] =1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

//sc -o(3V) & tc - o(V) + o(2E) = (total degree)


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        vector<int>ans;
        int V = adj.size();
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    ans.push_back(node);
                    visited[node] = 1;
                    for(auto it : adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
    // tc-> 0(V+E)
    // sc-> 0(V)  
//     Visited array

// Size = V
// → O(V)

// Queue

// In worst case, can hold all vertices
// → O(V)

// Answer vector

// Stores BFS traversal of all vertices
// → O(V)
};