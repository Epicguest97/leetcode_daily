class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m);
        for (int i = 0; i < m; ++i) {
            dp[i].resize(triangle[i].size(), 0);
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];           
                } else if (j == triangle[i].size() - 1) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];         
                } else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j-1], dp[i-1][j]);
                }
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
