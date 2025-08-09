class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int MOD = 1000000007;

        if (m == 1) {
            return (k == n - 1) ? 1 : 0;
        }

        // Precompute factorials
        vector<long long> fact(n);
        fact[0] = 1;
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i % MOD;

        long long comb = fact[n - 1] * modInverse(fact[k], MOD) % MOD;
        comb = comb * modInverse(fact[n - 1 - k], MOD) % MOD;

        long long res = m * comb % MOD;
        res = res * power(m - 1, n - 1 - k, MOD) % MOD;

        return res;
    }

private:
    long long power(long long x, long long y, int mod) {
        long long res = 1;
        x %= mod;
        while (y > 0) {
            if (y & 1) res = res * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return res;
    }

    long long modInverse(long long a, int mod) {
        return power(a, mod - 2, mod);
    }
};
