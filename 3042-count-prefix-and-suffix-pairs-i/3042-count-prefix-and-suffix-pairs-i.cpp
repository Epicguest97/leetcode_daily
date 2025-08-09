class Solution {
public:
    bool isPrefixAndSuffix(const string& str1, const string& str2) {
        // Check if str1 is both a prefix and suffix of str2
        return str2.rfind(str1, 0) == 0 && str2.find(str1, str2.size() - str1.size()) == str2.size() - str1.size();
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};
