// Count Good Numbers 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long a,long long b){
        long long res = 1;
        a = a%mod;
        while(b > 0){
            if(b & 1) res = (res*a)%mod;
            a = (a*a)%mod;
            b >>= 1;
        }
        return res%mod;
    }

    // using recursion 
    long long power(long long a,long long b){
        if(b == 0) return 1;
        long long res = 1;
        long long half = power(a,b/2);
        res = (half*half)%mod;
        if(b %2 == 1){
            res = (res*a)%mod;
        }
        return res%mod;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long x = power(5,even);
        long long y = power(4,odd);
        return (x*y)%mod;
    }
};