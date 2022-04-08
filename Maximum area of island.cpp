// https://hack.codingblocks.com/app/contests/2675/1552/problem


#include<iostream>
#include<vector>
using namespace std;

int dfsHelper(vector<vector<int>> grid, vector<vector<bool>>& visited, int m, int n, int i, int j){
    visited[i][j] = true;
    int count = 1;

    int delta_x[4] = {1, -1, 0, 0};
    int delta_y[4] = {0, 0, -1, 1};

    for(int k=0; k<4; k++){
        int nx = i + delta_x[k];
        int ny = j + delta_y[k];

        if(nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny] and !visited[nx][ny])
            count += dfsHelper(grid, visited, m, n, nx, ny);

    }
    return count;
}

int sol(vector<vector<int>> grid, int m, int n){
    vector<vector<bool>> visited(m, vector<bool> (n, false));
    int maxArea = 0;
    
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(grid[i][j] == 1 and !visited[i][j])
                maxArea = max(maxArea, dfsHelper(grid, visited, m, n, i, j));
    
    return maxArea;
}

int main(){
    int n,m;
    cin>>m>>n;

    vector<vector<int>> arr(m, vector<int> (n));

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    }

    cout<<sol(arr,m,n);
}