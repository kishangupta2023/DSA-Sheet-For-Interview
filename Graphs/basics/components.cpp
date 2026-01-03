// Connected Components in an Undirected Graph

// Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

// Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

// Note: You can return the components in any order, driver code will print the components in sorted order.

// Examples :

// Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
// Output: [[0, 1, 2], [3, 4]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // solution with dfs 
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited,vector<int>&components){
        visited[node] = 1;
        components.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,components);
            }
        }
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            int first = it[0];
            int second = it[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        vector<int>visited(V,0);
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>components;
                dfs(i,adj,visited,components);
                ans.push_back(components);
            }
        }
        return ans;
    }
    // tc->0(V+E)
    // sc->0(V+E)


    // Solution with bfs 
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            int first = it[0];
            int second = it[1];
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        vector<int>visited(V,0);
        vector<vector<int>>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                vector<int>components;
                queue<int>q;
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    visited[node] = 1;
                    components.push_back(node);
                    for(auto it :adj[node]){
                        if(!visited[it]){
                            q.push(it);
                            visited[it] = 1;
                        }
                    }
                }
                ans.push_back(components);
            }
        }
        return ans;
    }
};
