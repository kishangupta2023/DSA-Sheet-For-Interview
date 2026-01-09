//Djisktra's Algorithm
// for finding shortest path in weighted undirected graph 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> djisktra(int V,vector<vector<int>> adj[],int S){
         priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
        vector<int>dist(V);
        for(int i=0;i<V;i++) dist[i] =1e9;
        dist[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
// tc -ElogV here E is total no of edges and V is the no of nodes 

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
       priority_queue<pair<int,int>, 
            vector<pair<int,int>>, 
            greater<pair<int,int>>> pq;

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        pq.push({0, src});

        while(!pq.empty()){
            int len = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Skip outdated distance
            if(len > dist[node]) continue;

            for(auto &it : adj[node]){
                int edge = it.first;
                int weight = it.second;

                if(len + weight < dist[edge]){
                    dist[edge] = len + weight;
                    pq.push({dist[edge], edge});
                }
            }
        }
        return dist;
    }
};