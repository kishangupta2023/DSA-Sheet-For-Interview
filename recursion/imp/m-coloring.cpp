// // M-coloring problem 
// You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

// Note: The graph is indexed with 0-based indexing.

// Examples:

// Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
// Output: true
// Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isSafe(int node,vector<int>&color,vector<vector<int>>&adj,int n,int col){
        for(int it: adj[node]){
            if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    bool solve(int node,vector<int>&color,vector<vector<int>>&adj,int m,int n){
        if(node == n){
            return true;
        }
        for(int i=1;i<=m;i++){
            if(isSafe(node,color,adj,n,i)){
                color[node]= i;
                if(solve(node+1,color,adj,m,n)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(int V, vector<vector<int>> &edges, int m) {
        vector<vector<int>>adj(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,0);
        return solve(0,color,adj,m,V);
    }
};
