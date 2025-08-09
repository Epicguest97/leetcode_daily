class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;  // Special case when needle is empty
        
        int n = haystack.size();
        int m = needle.size();
        
        for (int i = 0; i <= n - m; i++) {  // Ensure there's enough space for comparison
            int j = 0;
            for (; j < m; j++) {
                if (haystack[i + j] != needle[j]) {
                    break;  // Mismatch found, break the inner loop
                }
            }
            if (j == m) {  // If we matched all characters in needle
                return i;
            }
        }
        
        return -1;  // No match found
    }
};
