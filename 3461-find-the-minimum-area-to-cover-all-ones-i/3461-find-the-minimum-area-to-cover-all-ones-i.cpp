class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minix=INT_MAX;
        int miniy=INT_MAX;
        int maxix=INT_MIN;
        int maxiy=INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    minix=min(minix,i);
                    miniy=min(miniy,j);
                    maxix=max(maxix,i);
                    maxiy=max(maxiy,j);
                }
            }
        }
        return (maxix-minix+1)*(maxiy-miniy+1);
    }
};