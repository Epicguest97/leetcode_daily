class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=0;j<n;j++){
            if(grid[0][j]==1)dfs(0,j,grid,m,n);
            if(grid[m-1][j]==1)dfs(m-1,j,grid,m,n);
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1)dfs(i,0,grid,m,n);
            if(grid[i][n-1]==1)dfs(i,n-1,grid,m,n);
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)count++;
            }
        }
        return count;
    }
private:
    void dfs(int row,int col,vector<vector<int>>&grid,int m,int n){
        if(row<0 || row>=m || col<0 || col>=n || grid[row][col]!=1)return;
        grid[row][col]=2;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            dfs(row + dr[i], col + dc[i], grid, m, n);
        }
    }
};