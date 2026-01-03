#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls ){
        vis[node] = 1;
        ls.push_back(node);
        //traverse all its neighbour
        for(auto it: adj[node]){
            if(vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        int vis[V] = {0};  
        int start = 0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls; 
    }
};
// tc- o(n) + (2*E)
// sc - o(n)+O(n)+o(n) == o(n)


class Solution {
  public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans){
        visited[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int V = adj.size();
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,ans);
            }
        }
        return ans;
    }
    // tc-> 0(V+2E) for undirected and for directed 0(V+E)
    // sc->0(3V) == 0(V)
};