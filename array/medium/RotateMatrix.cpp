// Rotate matrix by 90 degree 
#include<bits/stdc++.h>
using namespace std;

// brute force appoarch 
void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    int n = mat.size();
    int m = mat[0].size();
     vector<vector<int>>stored = mat;
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
            // mat[i][j] = stored[n-j-1][i];
            stored[j][n-i-1] = mat[i][j];
         }
     }
}
// tc -> 0(N*N)
// sc -> 0(N*N)

// better appoarch
// transpose the matrix 
// reverse every row  
void rotate(vector<vector<int> >& mat) {
    int n = mat.size();
    int m =mat[0].size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
    // tc -> 0(N+N/2)
}

