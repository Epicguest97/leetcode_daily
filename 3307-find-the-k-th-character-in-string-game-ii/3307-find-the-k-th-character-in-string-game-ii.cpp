class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        vector<long long> lengths;
        long long len = 1;
        for (int op : operations) {
            len *= 2;
            lengths.push_back(len);
            if (len >= k) break;
        }

        int level = lengths.size() - 1;
        int shift = 0;
        while (level >= 0) {
            long long half = lengths[level] / 2;
            int op = operations[level];
            if (k > half) {
                k -= half;
                if (op == 1) shift++;
            }
            level--;
        }

        char res = 'a';
        res = (res - 'a' + shift) % 26 + 'a';
        return res;
    }
};
