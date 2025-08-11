class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        vector<int> powers;
        for (int bit = 0; bit < 31; bit++) {
            if (n & (1 << bit)) {
                powers.push_back(1 << bit);
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            long long product = 1;
            for (int j = q[0]; j <= q[1]; j++) {
                product = (product * powers[j]) % MOD;
            }
            ans.push_back(product);
        }
        return ans;
    }
};
