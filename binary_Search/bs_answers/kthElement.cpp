// Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

// Examples :

// Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
// Output: 6
// Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        int n = (n1+n2);
        int ele = -1;
        int cnt = 0;
        int i=0;
        int j=0;
        while(i < n1 && j < n2){
            if(a[i] < b[j]){
                if(cnt == k-1){
                    ele = a[i];
                }
                cnt++;
                i++;
            }else{
                
                if(cnt == k-1){
                    ele = b[j];
                    
                }
                cnt++;
                j++;
            }
        }
        while(i<n1){
            if(cnt == k-1){
                ele = a[i];
            }
            
            cnt++;
            i++;
        }
        while(j<n2){
            if(cnt == k-1){
                ele = b[j];
            }
            cnt++;
            j++;
        }
        
        return ele;
    }

    // optimal approach
    double median(vector<int>& a, vector<int>& b,int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) return median(b,a,k);
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