class Solution {
public:
    int beautySum(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
        vector<int> freq(26, 0);
        for (int j = i; j < s.size(); ++j) {
            freq[s[j] - 'a']++;

            int maxi = 0, mini = INT_MAX;
            for (int f : freq) {
                if (f > 0) {
                    maxi = max(maxi, f);
                    mini = min(mini, f);
                }
            }
            count += (maxi - mini);
        }
    }
    return count;
}
};