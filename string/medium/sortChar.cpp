// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char,int>>freq(256);
        for(int i=0;i<s.size();i++){
            freq[s[i]].first = s[i];
            freq[s[i]].second++;
        }
        string t="";
        sort(freq.begin(),freq.end(),[](auto &a,auto &b){
            return a.second > b.second;
        });
        for(int i=0;i<256;i++){
            while(freq[i].second > 0){
                t +=freq[i].first;
                freq[i].second--;
            }
        }
        return t;
    }
    // Time complexity: O(n + 256 log 256) ≈ O(n).
    // Space complexity: O(256) = constant.
    
    string frequencySort(string s) {
        if (s.empty()) return "";

        // 1) Count frequencies
        unordered_map<char,int> freq;
        for (char c : s) freq[c]++;

        // 2) Create buckets where index = frequency
        int n = s.size();
        vector<string> buckets(n + 1); // buckets[0] unused
        for (auto &p : freq) {
            // append the character repeated p.second times into the bucket
            buckets[p.second].append(p.second, p.first);
        }

        // 3) Build result from highest frequency to lowest
        string res;
        res.reserve(n);
        for (int f = n; f >= 1; --f) {
            if (!buckets[f].empty()) res += buckets[f];
        }
        return res;
    }

};