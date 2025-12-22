// Job sequencing Problem
// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.
// Examples :

// Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
// Output: [2, 60]
// Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
// Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
// Output: [2, 127]
// Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int,int>>st;
        for(int i=0;i<deadline.size();i++){
            st.push_back({profit[i],deadline[i]});
        }
        int size = *max_element(deadline.begin(),deadline.end());
        
        sort(st.begin(),st.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first > b.first;
        });
        
        int maxProfit = 0;
        int cnt = 0;
        vector<int>hash(size+1,-1);
        
        for(int i =0;i<deadline.size();i++){
            for(int j = st[i].second;j >= 1;j--){
                if(hash[j] == -1){
                    cnt++;
                    hash[j] = st[i].first;
                    maxProfit += st[i].first;
                    break;
                }
            }
        }
        return {cnt,maxProfit};
    }
    // Time: O(n log n + n * maxDeadline)
    // Space: O(maxDeadline)
};