// String to Integer(atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fun(string s,int i,int state,int sign,long long value){
        if(i >= s.size()) return sign*value;
        if(state == 0){
            if(s[i] == ' ') return fun(s,i+1,0,1,value);
            return fun(s,i+1,1,1,value);
        }
        if(state == 1){
            if(s[i] == '-') return fun(s,i+1,2,-1,value);
            if(s[i] == '+') return fun(s,i+1,2,1,value);
            return fun(s,i,2,1,value); 
        }
        if(state == 2){
            value = value*10 + (s[i]-'0');
            if(sign == 1 && value > INT_MAX) return INT_MAX;
            if(sign == -1 && -value < INT_MIN) return INT_MIN;
            return fun(s,i+1,state,sign,value);
        }
        return value*sign;
    }
    int myAtoi(string s) {
        return fun(s,0,0,1,0);
    }
    
//     Time Complexity	O(n)	Each character processed once
// Space Complexity	O(n)
};