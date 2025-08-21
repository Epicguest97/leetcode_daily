class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>nums(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)nums[i][j]=0;
                else nums[i][j]=(j==0 ? 1: nums[i][j-1]+1);
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int width=nums[i][j];
                for(int k=i;k>=0 && width>0;k--){
                    width=min(width,nums[k][j]);
                    res+=width;
                }
            }
        }
        return res;
    }
};