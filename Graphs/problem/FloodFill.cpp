// Fllod filled Algorithm 
// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill:

// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.

 

// Example 1:

// Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

// Output: [[2,2,2],[2,2,0],[2,0,1]]

#include<iostream>
#include<vector>
#include<Queue>
using namespace std;
class Solution {
    private:
    void dfs(int row, int col,vector<vector<int>>&ans,vector<vector<int>>& image,int newColor,int delRow[],int delCol[],int iniColor){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;1<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >=0 && nrow<n && ncol >=0 && ncol<n && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor ){
                dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);
            }
        }

    }
    public:
    vector<vector<int>> floodFill(vector<vector<int>> &image , int sr,int sc, int newColor){
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);
        return ans;
    } 

};
//tc - o(n*m*4)= o(n*m)
//sc - O(n*m) + o(n*m))


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pixel = image[sr][sc];
        if(pixel == color) return image;
        vector<vector<int>>ans;
        ans = image;
        int n = ans.size();
        int m = ans[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            ans[r][c] = color;
            vis[r][c] = 1;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && ans[nrow][ncol] == pixel && !vis[nrow][ncol]){
                    q.push({nrow,ncol});
                    ans[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return ans;
    }
    // tc-> 0(N*M*4) == 0(N*M)
    // sc -> 0(N*M) + 0(N*M) == 0(N*M) 
    

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int pixel = image[sr][sc];
        if (pixel == color) return image;

        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    image[nrow][ncol] == pixel) {

                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
    // no extra space only queue space is used 


};