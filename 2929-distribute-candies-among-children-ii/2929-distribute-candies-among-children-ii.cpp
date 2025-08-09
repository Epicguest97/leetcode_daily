class Solution {
public:
   
    long long comb2(long long n) {
        if (n < 0) return 0;
        return n * (n - 1) / 2;
    }

    long long distributeCandies(int n, int limit) {
        auto C = [](long long x) {
            if (x < 0) return 0LL;
            return (x + 2) * (x + 1) / 2;
        };

        long long total = C(n);

        for (int i = 0; i < 3; ++i) {
            total -= C(n - (limit + 1));
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                total += C(n - 2 * (limit + 1));
            }
        }

        total -= C(n - 3 * (limit + 1));

        return total;
    }
};
