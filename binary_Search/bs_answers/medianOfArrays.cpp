// Median of 2 Sorted Arrays of Different Sizes 
// Given two sorted arrays a[] and b[], find and return the median of the combined array after merging them into a single sorted array.

// Examples:

// Input: a[] = [3, 5, 6, 12, 15], b[] = [3, 4, 6, 10, 10, 12]
// Output: 6
// Explanation: The merged array is [3, 3, 4, 5, 6, 6, 10, 10, 12, 12, 15]. So the median of the merged array is 6.
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int>mergeSort(vector<int>&a,vector<int>&b){
        int n = a.size();
        int m = b.size();
        vector<int>ans;
        int i=0;
        int j =0;
        while(i<n && j < m){
            if(a[i] < b[j]){
                ans.push_back(a[i]);
                i++;
            }else{
                ans.push_back(b[j]);
                j++;
            }
        }
        while(i <n){
            ans.push_back(a[i]);
            i++;
        }
        while(j <m){
            ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        vector<int>mergeArray = mergeSort(a,b);
        int n = mergeArray.size();
        double ans =0;
        if(n % 2 == 0){
            ans = (mergeArray[n/2]+mergeArray[n/2 -1])/2.0;
        }else{
            ans = mergeArray[n/2];
        }
        return ans;
    }
    //tc-> 0(N+M)
   // sc -> 0(N+M)

    // better Approach 
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        int n = (n1+n2);
        int ind1 = ((n/2)-1);
        int ind2 = (n/2);
        int ele1 = -1;
        int ele2 =-1;
        int cnt = 0;
        int i=0;
        int j=0;
        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                if(cnt == ind1){
                    ele1 = a[i];
                }
                if(cnt == ind2){
                    ele2 = a[i];
                }
                cnt++;
                i++;
            }else{
                if(cnt == ind1){
                    ele1 = b[j];
                }
                if(cnt == ind2){
                    ele2 = b[j];
                }
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt == ind1){
                ele1 = a[i];
            }
            if(cnt == ind2){
                ele2 = a[i];
            }
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt == ind1){
                ele1 = b[j];
            }
            if(cnt == ind2){
                ele2 = b[j];
            }
            cnt++;
            j++;
        }
        double ans = 0;
        if(n%2 == 1){
            ans = ele2;
        }else{
            ans = (ele1+ele2)/2.0;
        }
        return ans;
    }

    // optimal Solution 
     double median(vector<int>& a, vector<int>& b) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return median(b,a);
        int low = 0;
        int high = n1;
        int left = (n1+n2+1)/2;
        int n = n1+n2;
        while(low <= high){
            int mid1 = (low+high) >> 1;
            int mid2 = left-mid1;
            int l1 =INT_MIN,l2 =INT_MIN;
            int r1 =INT_MAX,r2=INT_MAX;
            if(mid1 < n1) r1 = a[mid1];
            if(mid2 < n2) r2 = b[mid2];
            if(mid1-1 >= 0) l1 = a[mid1-1];
            if(mid2-1 >= 0) l2 = b[mid2-1];
            if(l1 <=r2 && l2 <= r1){
                if(n%2 == 1) return max(l1,l2);
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }else if(l1 >r2) high = mid1-1;
            else low = mid1+1;
        }
        return 0;
    }

};