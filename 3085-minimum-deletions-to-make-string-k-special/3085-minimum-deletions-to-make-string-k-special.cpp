class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        vector<int> usedFreq;
        for (int f : freq) {
            if (f > 0) usedFreq.push_back(f);
        }

        sort(usedFreq.begin(), usedFreq.end());
        int minDeletions = INT_MAX;

        for (int target : usedFreq) {
            int deletions = 0;
            for (int f : usedFreq) {
                if (f < target) {
                    deletions += f;
                } else if (f > target + k) {
                    deletions += f - (target + k);
                }
            }
            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
