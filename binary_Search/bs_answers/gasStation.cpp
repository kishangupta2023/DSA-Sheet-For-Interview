// Minimise Maximum Distance Between Gas Station 
// We have a horizontal number line. On that number line, we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
// Note: stations is in a strictly increasing order.
// Examples:
// Input: stations[] = [1, 2, 3, 4, 5], k = 2
// Output: 1.00
// Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        vector<int>howMany(n-1,0);
        for(int gasStations = 1;gasStations<=K;gasStations++){
            long double maxSection = -1;
            int maxInd = -1;
            for(int i=0;i<n-1;i++){
                long double diff = (stations[i+1]-stations[i]);
                long double sectionLength = diff/(long double)(howMany[i]+1);
                if(sectionLength > maxSection){
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }
            howMany[maxInd]++;
        }
        long double maxAns = -1;
        for(int i=0;i<n-1;i++){
            long double diff = (stations[i+1]-stations[i]);
            long double sectionLength = diff/(long double)(howMany[i]+1);
            maxAns = max(maxAns,sectionLength);
        }
        return maxAns;
    }
    // tc-> 0(K*N)+0(N)

    // better using priority queue 
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        if(n <= 1) return 0.0;
        priority_queue<pair<long double,int>>pq;
        vector<int>howMany(n-1,0);
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int gasStations = 1;gasStations<=K;gasStations++){
            auto tp = pq.top();
            pq.pop();
            int secInd = tp.second;
            howMany[secInd]++;
            long double iniDiff = stations[secInd+1]-stations[secInd];
            long double newSecLen = iniDiff/(long double)(howMany[secInd]+1);
            pq.push({newSecLen, secInd});
        }
        return (double)pq.top().first;
    }
    // tc -> 0(NlogN) + 0(klogN)
    // sc ->0(N-1)

    // optimal Solution 
    int numberOfGasStationsRequired(long double dist,vector<int>&arr){
        int cnt =0;
        for(int i=1;i<arr.size();i++){
            int numberInBetween = ((arr[i]-arr[i-1]/dist)/dist);
            if((arr[i]-arr[i-1])/dist == numberInBetween+dist){
                numberInBetween--;
            }
            cnt+=numberInBetween;
        }
        return cnt;
    }
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        if(n <= 1) return 0.0;
        long double low =0;
        long double high = 0;
        for(int i=0;i<n-1;i++){
            high = max(high,(long double)(stations[i+1]-stations[i]));
        }
        long double diff = 1e-6;
        while(high-low > diff){
            long double mid = (low+mid)/(2.0);
            int cnt = numberOfGasStationsRequired(mid,stations);
            if(cnt > K){
                low = mid;
            }else{
                high = mid;
            }
        }
        return high;
    }
};