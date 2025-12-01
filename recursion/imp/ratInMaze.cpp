// Rat in maze 
// Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

// The matrix contains only two possible values:

// 0: A blocked cell through which the rat cannot travel.
// 1: A free cell that the rat can pass through.
// Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
// If no path exists, return an empty list.

// Note: Return the final result vector in lexicographically smallest order.

// Examples:

// Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
// Output: ["DDRDRR", "DRDDRR"]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int row,int col,string &s,vector<string>&ans,vector<vector<int>>& maze,int n){
        if(row < 0 || col < 0 || row >= n || col >= n || maze[row][col] == 0) return;
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        } 

        maze[row][col] = 0;
        s += 'D';
        solve(row+1,col,s,ans,maze,n);
        s.pop_back(); 
        s += 'U';
        solve(row-1,col,s,ans,maze,n);
        s.pop_back(); 
        s += 'L';
        solve(row,col-1,s,ans,maze,n);
        s.pop_back(); 
        s += 'R';
        solve(row,col+1,s,ans,maze,n);
        s.pop_back();

        maze[row][col] =1;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        if (maze[0][0] == 0) return ans;
        string s;
        int n = maze.size();
        solve(0,0,s,ans,maze,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};