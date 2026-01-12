// Network Delay Time

// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
// Example 1:
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int size = times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<size;i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>time(n+1,1e9);
        time[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int v=  it.first;
                int w = it.second;
                if(t + w < time[v]){
                    time[v] = t + w;
                    pq.push({t+w,v});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<n+1;i++){
            if(time[i] == 1e9) return -1;
            maxi = max(maxi,time[i]);
        }
        return maxi;
    }
};