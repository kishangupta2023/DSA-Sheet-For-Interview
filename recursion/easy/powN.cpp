// pow(x,n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        if(x == 0) return 0.0;
        bool neg = false;
        long long nn = n;
        if(n < 0){
            nn= -n;
            neg = true;
        }
        double ans = 1.0;
        for(long long i=0;i<nn;i++){
            ans *=x;
        }
        return neg ? 1.0/ans: ans;
    }
    // tc -> 0(N)
    // sc -> 0(1)

    double myPow(double x,int n){
        double ans = 1.0;
        long long nn = n;
        if(nn < 0) nn = -1*n;
        while(nn){
            if(nn %2){
                ans = ans*x;
                nn = nn-1;
            }else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n <0) ans = (double)(1.0)/(double)(ans);
        return ans;
    }

    // recursive 
    double fun(double x,long long n){
        if(n == 0) return 1.0;
        double half = fun(x,n/2);
        if(n %2 == 0){
            return half*half;
        }
        return x*half*half;
    }
    double myPow(double x, int n) {
        long long nn = n;
        if(nn <0){
            x = 1.0/x;
            nn = -nn;
        }
        return fun(x,nn);
    }
    // tc- > 0(logn)
    
};