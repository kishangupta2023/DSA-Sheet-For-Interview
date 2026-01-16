// kruskal Algorithm 
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
// ulp_u =ultimate parent of u 
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
    public:
    int spanningTree(int V,vector<vector<int>> adj[]){
        // o(N)
       vector<pair<int,pair<int,int>>> edges;
       // o(N+E)
       for(int i=0;i<V;i++){
          for(auto it: adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
          }
       }
       DisjointSet ds(V);
       // MlogN
       sort(edges.begin(),edges.end());
       int mstWt = 0;
       // N*4*alfa*2
       for(auto it:edges){
        int wt  = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if(ds.findUPar(u) != ds.findUPar(v)){
            mstWt += wt;
            ds.unionBySize(u,v);
        }
       }
       return mstWt;
    }
};

// User function Template for C++
class DisjointSets{
    vector<int>rank,parent;
    public:
    DisjointSets(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i] = i;
    }
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unionByRank(int x,int y){
        int ulp_x = find(x);
        int ulp_y = find(y);
        if(ulp_x == ulp_y) return;
        if(rank[ulp_x] < rank[ulp_y]){
            parent[ulp_x] = ulp_y;
        }
        else if(rank[ulp_x] > rank[ulp_y]){
            parent[ulp_y] = ulp_x;
        }
        else{
            parent[ulp_y] = ulp_x;
            rank[ulp_x]++;
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        vector<pair<int,pair<int,int>>>edge;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            edge.push_back({w,{u,v}});
            edge.push_back({w,{v,u}});
        }
        sort(edge.begin(),edge.end());
        int weight = 0;
        DisjointSets ds(V);
        for(int i=0;i<edge.size();i++){
            int w = edge[i].first;
            int u = edge[i].second.first;
            int v = edge[i].second.second;
            if(ds.find(u) != ds.find(v)){
                weight += w;
                ds.unionByRank(u,v);
            }
        }
        return weight;
    }
};