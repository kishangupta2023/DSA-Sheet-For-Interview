// // Stirng to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// Whitespace: Ignore any leading whitespace (" ").
// Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
// Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
// Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
// Return the integer as the final result.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int ind = 0;
        int n = s.size();

        // skip spaces
        while(ind < n && s[ind] == ' ') ind++;

        // sign
        bool neg = false;
        if(ind < n && (s[ind] == '-' || s[ind] == '+')){
            if(s[ind] == '-') neg = true;
            ind++;
        }

        // skip leading zeros
        while(ind < n && s[ind] == '0') ind++;

        string r = "";
        for(int i = ind; i < n; i++){
            // FIX: use AND instead of OR
            if(s[i] >= '0' && s[i] <= '9'){
                r += s[i];
            } else {
                break;
            }
        }

        if(r == "") return 0;

        // convert safely (handle overflow manually)
        for(char c : r){
            res = res * 10 + (c - '0');
            if(!neg && res > INT_MAX) return INT_MAX;
            if(neg && -res < INT_MIN) return INT_MIN;
        }

        if(neg) res = -res;
        return (int)res;
    }

    int myAtoi(string s) {
        long long res = 0;
        int i = 0, n = s.size();

        // 1. Skip spaces
        while(i < n && s[i] == ' ') i++;

        // 2. Check sign
        int sign = 1;
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        // 3. Convert digits
        while(i < n && isdigit(s[i])){
            res = res*10 + (s[i] - '0');

            // handle overflow
            if(sign == 1 && res > INT_MAX) return INT_MAX;
            if(sign == -1 && -res < INT_MIN) return INT_MIN;

            i++;
        }

        return res * sign;
    }
};
