// // Letter Combinations of a phone number 
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public: 
    void generate(int ind,string &current,string &digits,vector<string>&result,unordered_map<char,string>&mpp){
        if(ind == digits.size()){
            result.push_back(current);
            return;
        }
        char digit = digits[ind];
        string currentString = mpp[digit];
        for(char c : currentString){
            current.push_back(c);
            generate(ind+1,current,digits,result,mpp);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>result;
        if(digits.empty()) return result;
        unordered_map<char,string>mpp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        string current = "";
        generate(0,current,digits,result,mpp);
        return result;
    }
    // tc -> 0(4pow(n).n)   each combinations takes 0(n) to build(push/pop)
    // sc -> 0(4pow(n).n)



    // we can use array to check the char as it is faster and simpler 
    // vector<string> mapping = {
    //         "",     // 0
    //         "",     // 1
    //         "abc",  // 2
    //         "def",  // 3
    //         "ghi",  // 4
    //         "jkl",  // 5
    //         "mno",  // 6
    //         "pqrs", // 7
    //         "tuv",  // 8
    //         "wxyz"  // 9
    //     };

};

class Solution {
public:
    void backtrack(int ind, string &current, const string &digits,
                   vector<string> &result, const vector<string> &mapping) {
        if (ind == digits.size()) {
            result.push_back(current);
            return;
        }

        int d = digits[ind] - '0';
        const string &chars = mapping[d];

        for (char c : chars) {
            current.push_back(c);
            backtrack(ind + 1, current, digits, result, mapping);
            current.pop_back();   // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;

        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current;
        backtrack(0, current, digits, result, mapping);
        return result;
    }
};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result = {""};

        for (char d : digits) {
            vector<string> next;
            const string &chars = mapping[d - '0'];

            for (const string &s : result) {
                for (char c : chars) {
                    next.push_back(s + c);
                }
            }

            result.swap(next);
        }

        return result;
    }
};
