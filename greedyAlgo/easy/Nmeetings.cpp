// You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

// Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

// Examples :

// Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
// Output: 4
// Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int count =0;
        vector<pair<int,int>>st;
        for(int i=0;i<end.size();i++){
            st.push_back({end[i],i});
        }
        sort(st.begin(),st.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first < b.first;
        });
        int currentEnd = -1;
        for(auto it : st){
            if(it.first > currentEnd && start[it.second] > currentEnd){
                count++;
                currentEnd = it.first;
            }
        }
        return count;
    }
};
// tc -> 0(nlogn)
// sc -> 0(n)
