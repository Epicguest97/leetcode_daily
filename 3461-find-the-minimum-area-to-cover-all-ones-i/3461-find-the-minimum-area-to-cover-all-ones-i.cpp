class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minix=m;
        int miniy=n;
        int maxix=-1;
        int maxiy=-1;
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