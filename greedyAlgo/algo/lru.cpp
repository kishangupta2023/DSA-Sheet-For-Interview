// Least Recently Used (LRU) page Replacement Algorithm 
// in operating systems that use paging for memory management, page replacement algorithm is needed to decide which page needs to be replaced when the new page comes in. Whenever a new page is referred and is not present in memory, the page fault occurs and Operating System replaces one of the existing pages with a newly needed page.

// Given a sequence of pages in an array pages[] of length N and memory capacity C, find the number of page faults using Least Recently Used (LRU) Algorithm. 

// Note:- Before solving this example revising the OS LRU cache mechanism is recommended.

// Example 1:

// Input: N = 9, C = 4
// pages = {5, 0, 1, 3, 2, 4, 1, 0, 5}
// Output: 8
// Explaination: memory allocated with 4 pages 5, 0, 1, 
// 3: page fault = 4
// page number 2 is required, replaces LRU 5: 
// page fault = 4+1 = 5
// page number 4 is required, replaces LRU 0: 
// page fault = 5 + 1 = 6
// page number 1 is required which is already present: 
// page fault = 6 + 0 = 6
// page number 0 is required which replaces LRU 3: 
// page fault = 6 + 1 = 7
// page number 5 is required which replaces LRU 2: 
// page fault = 7 + 1  = 8.

#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
    int pageFaults(int N, int C, int pages[]) {
        // code here
        vector<int>cap;
        int faults =0;
        
        for(int i=0;i<N;i++){
            auto it = find(cap.begin(),cap.end(),pages[i]);
            
            if(it != cap.end()){
                cap.erase(it);
                cap.push_back(pages[i]);
            }else{
                faults++;
                if(cap.size() == C){
                    cap.erase(cap.begin());
                    cap.push_back(pages[i]);
                }
                else{
                    cap.push_back(pages[i]);
                }
            }
        }
        return faults;
    }
    // tc -> 0(N*C)
    // sc -> 0(C)


    // for optimization we have used iterator 
    int pageFaults(int N, int C, int pages[]) {
        unordered_map<int, list<int>::iterator> mp;
        list<int> lru;
        int faults = 0;

        for(int i = 0; i < N; i++) {
            int page = pages[i];

            // Page HIT
            if(mp.find(page) != mp.end()) {
                lru.erase(mp[page]);
            }
            // Page FAULT
            else {
                faults++;
                if(lru.size() == C) {
                    int least = lru.front();
                    lru.pop_front();
                    mp.erase(least);
                }
            }

            // Insert as most recently used
            lru.push_back(page);
            mp[page] = prev(lru.end());
        }
        return faults;
    }
    // tc -> 0(N)
    // sc -> 0(C)

};