class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>rotten;
        int fresh=0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)rotten.push({i,j});
                else if(grid[i][j]==1)fresh++;
            }
        }
        vector<pair<int,int>>directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int time=0;
        while(!rotten.empty() && fresh>0){
            int s = rotten.size();
            for(int k=0;k<s;k++){
                auto [i,j] =rotten.front();
                rotten.pop();
                for(auto [dx,dy] : directions){
                    int ni = dx+i;
                    int nj= dy+j;
                    if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        fresh--;
                        rotten.push({ni,nj});
                    }
                } 
            }
            time++;
        }
        return fresh==0 ? time : -1;
    }

};