class Solution {
public:
    int MOD = 1e9 + 7;
    vector<long long> powers;
    vector<vector<int>> dp;

    int solve(int idx, int remaining) {
        if (remaining == 0) return 1;
        if (idx >= powers.size() || remaining < 0) return 0;
        if (dp[idx][remaining] != -1) return dp[idx][remaining];
        long long include = solve(idx + 1, remaining - powers[idx]);
        long long exclude = solve(idx + 1, remaining);

        return dp[idx][remaining] = (include + exclude) % MOD;
    }

    int numberOfWays(int n, int x) {
        for (int i = 1; pow(i, x) <= n; i++) {
            powers.push_back((long long)pow(i, x));
        }
        dp.assign(powers.size(), vector<int>(n + 1, -1));
        return solve(0, n);
    }
};
