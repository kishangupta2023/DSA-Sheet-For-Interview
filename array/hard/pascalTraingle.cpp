// Given Row and column tell the element at that row and col in the pascal traingle 
// for this do r-1^C^c-1 = n!/r!*(n-r)!

// 2-> for printing a full column in a pascal traingle 

// 3 ->  Print entire pascal traingle 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    // 1->
    public:
    int factorial(int n){
        if(n == 1 || n == 0) return 1;
        return n*factorial(n-1);
    }
    int element(int row,int col){
        int ans =(factorial(row-1)/(factorial(col-1)*factorial(row-col)));
        return ans;
    }
    // another solution 
    int funNCr(int n,int r){
        int res = 1;
        for(int i=0;i<r;i++){
            res = res*(n-i);
            res /=(i+1);
        }
        return res;
    }
    // tc ->0(r)
    // sc -> 0(1)


    //2-> for printing a full column in a pascal traingle 
    vector<int> printCol(int row){
        vector<int>ans;
        for(int c =1;c<=row;c++){
            int x = funNCr(row-1,c-1);
            ans.push_back(x);
        }
        return ans;
    }
    // tc -> 0(N*R)

    // better approach 
    vector<int> printCol(int n){
        vector<int>result;
        int ans = 1;
        result.push_back(ans);
        for(int i =1;i<n;i++){
            ans = ans*(n-i);
            ans = ans/i;
            result.push_back(ans);
        }
        return result;
    }
    // tc -> 0(N)
    // sc -> 0(1)

    // 3 ->  Print entire pascal traingle 
    //bruteforce approach 
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
     
        for(int i=1;i<=numRows;i++){
            vector<int>col;
            for(int c =1;c<=i;c++){
            int x = funNCr(i-1,c-1);
            col.push_back(x);
        }
            ans.push_back(col);
        }
        return ans;
    }
    // tc 0(N*N*r) == 0(N*N*N)
    
    // better approach
     vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        for(int i=1;i<=numRows;i++){
            vector<int>result;
            int ans = 1;
            result.push_back(ans);
            for(int j=1;j<i;j++){
            ans = ans*(i-j);
            ans = ans/j;
            result.push_back(ans);
            }
            res.push_back(result);
        }
        return res;
    }
    // tc ->0(N*N)

};

