// Roman to Int value
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ans =0;
        stack<pair<char,int>> st;
        unordered_map<char,int> v = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
       };
        for(int i=s.size()-1;i>=0;i--){
            if(st.empty()){
                ans += v[s[i]];
                st.push({s[i],v[s[i]]});
            }
            else{
                if(st.top().second <= v[s[i]]){
                    ans += v[s[i]];
                    st.push({s[i],v[s[i]]});
                }else{
                    ans -= v[s[i]];
                    st.push({s[i],v[s[i]]});
                }
            }
        }
        return ans;
    }
    // tc- > 0(N)
    // sc -0(N)
// bcz of stack

    int romanToInt(const string &s) {
    static const unordered_map<char,int> val = {
        {'I',1}, {'V',5}, {'X',10},
        {'L',50}, {'C',100}, {'D',500}, {'M',1000}
    };
    int n = s.size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int cur = val.at(s[i]);
        if (i+1 < n && cur < val.at(s[i+1])) {
            result -= cur; // subtractive pair
        } else {
            result += cur;
        }
    }
    return result;
}
 // tc -0(N)
// sc -0(1)

 // Convert integer (1..3999) to Roman numeral string
string intToRoman(int num) {
    // values and their Roman representations in descending order
    static const vector<int> values = 
        {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    static const vector<string> symbols = 
        {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    string res;
    res.reserve(16); // small optimization
    for (size_t i = 0; i < values.size() && num > 0; ++i) {
        while (num >= values[i]) {
            res += symbols[i];
            num -= values[i];
        }
    }
    return res;
}
// tc - 0(1)
// sc - 0(1)
};