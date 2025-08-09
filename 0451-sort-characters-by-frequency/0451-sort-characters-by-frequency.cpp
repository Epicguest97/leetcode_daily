class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        for (char c : s) {
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]);
        }

        vector<vector<char>> buckets(maxFreq + 1);
        for (auto &p : freq) {
            buckets[p.second].push_back(p.first);
        }

        string result;
        for (int i = maxFreq; i >= 1; --i) {
            for (char c : buckets[i]) {
                result += string(i, c);  
            }
        }

        return result;
    }
};
