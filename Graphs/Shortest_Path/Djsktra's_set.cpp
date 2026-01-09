// Djisktra's Algorithm with SET 
// erase -> already existing  values
#include<bits/stdc++.h>
using namespace std; 

// set is used as it store the element in ascending order also the deletion in set is of logn time which is helpful for avoiding non usefull itaration for the greater distance value of node 
class Solution{
    public:
    vector<int> djstra(int V,vector<vector<int>> adj[],int S){
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        st.insert({0,S});
        dist[S] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];

                if(dis + edgeW < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
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
       set<pair<int,int>>st;

        vector<int> dist(V, 1e9);
        dist[src] = 0;

        st.insert({0, src});

        while(!st.empty()){
            auto it = *(st.begin());
            int len = it.first;
            int node = it.second;
            st.erase(it);
            for(auto it : adj[node]){
                int edge = it.first;
                int weight = it.second;
                if(len + weight < dist[edge]){
                    if(dist[edge] != 1e9){
                        st.erase({dist[edge],edge});
                    }
                    dist[edge] = len + weight;
                    st.insert({len+weight,edge});
                }
            }
        }
        return dist;
    }
};