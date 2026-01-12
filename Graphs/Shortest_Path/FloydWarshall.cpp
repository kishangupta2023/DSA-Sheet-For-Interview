// Floyd Warshall Algorithm 
//MUlti Source shortest path also detect negative cycles 
// How to detect a negative cycle -> if(cost[i][i] < 0) then negative cycle exists 

// the problem is to find the shortest distance btw every pair of vertices in a given edge-weighted directed Graph 
// Do it inplace 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]); 
                }
            }
        }



        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }
    }

};

// sc -o(n2)
// tc- o(n3)

// You are given a weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
// The graph may contain negative edge weights, but it does not contain any negative weight cycles.

// Your task is to find the shortest distance between every pair of nodes i and j in the graph.

// Note: Modify the distances for every pair in place.

// Examples :

// Input: dist[][] = [[0, 4, 108, 5, 108], [108, 0, 1, 108, 6], [2, 108, 0, 3, 108], [108, 108, 1, 0, 2], [1, 108, 108, 4, 0]]

// Output: [[0, 4, 5, 5, 7], [3, 0, 1, 4, 6], [2, 6, 0, 3, 5], [3, 7, 1, 0, 2], [1, 5, 5, 4, 0]]
// User function template for C++
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int n = dist.size();
        for(int k= 0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k] == 1e8 || dist[k][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
};