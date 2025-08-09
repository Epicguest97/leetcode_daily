class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int original = image[sr][sc];
        if(original!=color){
            dfs(image,sr,sc,color,original);
        }
        
        return image;
    }
private:
    void dfs(vector<vector<int>>&image,int sr,int sc,int color,int original){
        int rows = image.size();
        int cols = image[0].size();
        if (sr < 0 || sr >= rows || sc < 0 || sc >= cols || image[sr][sc] != original)return;
        image[sr][sc] = color;
        vector<pair<int,int>>directions ={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto[dx,dy] : directions){
            int ni = sr + dx;
            int nj = sc + dy;
            dfs(image,ni,nj,color,original);
        }
    }
};