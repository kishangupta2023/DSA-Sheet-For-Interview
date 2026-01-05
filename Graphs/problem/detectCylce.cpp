// Detect a cycle in a undirected Graph using BFS 
#include<iostream>
#include<vector>
#include<Queue>
using namespace std;
class Solution{
    private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
   


    public:
    bool isCycle(int V,vector<int>adj[]){
    int vis[V] = {0};
    for(int i =0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;

}
// tc-o(n+2E) +o(n)
// sc-o(N) + O(N) == o(N)
};


class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
              queue<pair<int,int>>q;
             q.push({i,-1});
            while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            visited[node] = 1;
            
            for(auto it: adj[node]){
                if(!visited[it]){
                    q.push({it,node});
                    visited[it] = 1;
                    }else if(parent != it){
                        return true;
                    }
                }
            }
            }
        }
        return false;
    }
    // tc->0(2E) + 0(V+2E)==0(V+E)
    // sc->0(V+E)+0(V)+0(V) == 0(V+E)
};