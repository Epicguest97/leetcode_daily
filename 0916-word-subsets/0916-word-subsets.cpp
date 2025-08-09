class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Helper function to count character frequencies
        auto countFrequencies = [](const string& word) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            return freq;
        };

        // Step 1: Compute maximum frequency requirement for words2
        vector<int> maxFreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq = countFrequencies(word);
            for (int i = 0; i < 26; ++i) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        // Step 2: Filter words1 based on maxFreq
        vector<string> result;
        for (const string& word : words1) {
            vector<int> freq = countFrequencies(word);
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                result.push_back(word);
            }
        }

        return result;
    }
};
