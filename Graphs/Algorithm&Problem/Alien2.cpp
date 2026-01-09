// A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

// Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

// However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

// A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

// Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

// Examples:

// Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
// Output: true
// Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
// The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
// The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
// The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
// The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
// So, 'b' → 'd' → 'a' → 'c' is a valid ordering.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string findOrder(vector<string> &words){
        unordered_map<char,vector<char>>adj;
        unordered_map<char,int>indegree;
        for(int i=0;i<words.size();i++){
            for(char c : words[i]){
                indegree[c] = 0;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            bool found = false;
            int len = min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]].push_back(s2[j]);
                    indegree[s2[j]]++;
                    found = true;
                    break;
                }
            }
            if(!found && s1.size() > s2.size()){
                return "";
            }
        }
        queue<char>q;
        for(auto it:indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        string s = "";

        while(!q.empty()){
            char c = q.front();
            s += c;
            q.pop();
            for(char it: adj[c]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(s.size() != indegree.size()) return "";
        return s;
    }
//     Time & Space Complexity

// Time: O(N * L + V + E)

// N = number of words

// L = average word length

// V = unique characters

// E = ordering rules

// Space: O(V + E)
};