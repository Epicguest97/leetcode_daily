class Solution {
public:
    int maxDifference(string s) {
        vector<int> hash(26, 0);
        
        for (char c : s) {
            hash[c - 'a']++;
        }

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < 26; i++) {
            if (hash[i] > 0 && hash[i] % 2 == 1) {
                maxi = max(maxi, hash[i]);
            }
            if (hash[i] > 0 && hash[i] % 2 == 0) {
                mini = min(mini, hash[i]);
            }
        }

       
        if (maxi == INT_MIN || mini == INT_MAX) return 0;
        
        return maxi - mini;
    }
};
