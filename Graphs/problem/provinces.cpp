//Number of provinces | connected graph
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.
// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int node,vector<vector<int>>&adj,vector<int>&visited){
        visited[node] = 1;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,adj,visited);
            }
        }
        return ans;
    }
};
// tc-> 0(n*n)
// sc -> 0(n*n)

 void dfs(int node,vector<vector<int>>&isConnected,vector<int>&visited){
        visited[node] = 1;
        int n = isConnected[0].size();
        for(int j=0;j<n;j++){
            if(isConnected[node][j] == 1 && !visited[j]){
                dfs(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i,isConnected,visited);
            }
        }
        return ans;
    }
    // tc->0(n*n)
    // sc->0(n)


    // bfs solution 
    class Solution {
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                queue<int>q;
                q.push(i);
                ans++;
                visited[i] =1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j] == 1 && !visited[j]){
                            q.push(j);
                            visited[j] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};