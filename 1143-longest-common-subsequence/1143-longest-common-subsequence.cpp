class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // Initialize with -1 (uncomputed)
        return helper(0, 0, text1, text2, dp);
    }

    int helper(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if (i == text1.size() || j == text2.size())
            return 0;

        if (dp[i][j] != -1)  // Already computed
            return dp[i][j];

        if (text1[i] == text2[j])
            dp[i][j] = 1 + helper(i + 1, j + 1, text1, text2, dp);
        else
            dp[i][j] = max(helper(i + 1, j, text1, text2, dp), helper(i, j + 1, text1, text2, dp));

        return dp[i][j];
    }
};
