class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        // If the length of the string is odd, it's impossible to make it valid.
        if (n % 2 != 0) return false;

        // Left-to-right check
        int open = 0; // Tracks number of '(' needed
        int wildcards = 0; // Tracks number of modifiable characters
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                wildcards++;
            } else if (s[i] == '(') {
                open++;
            } else {
                // This is a locked ')'
                open--;
            }
            // If unmatched ')' exceeds available wildcards + '(', return false
            if (open + wildcards < 0) return false;
        }

        // Right-to-left check
        int close = 0; // Tracks number of ')' needed
        wildcards = 0; // Reset wildcards counter
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                wildcards++;
            } else if (s[i] == ')') {
                close++;
            } else {
                // This is a locked '('
                close--;
            }
            // If unmatched '(' exceeds available wildcards + ')', return false
            if (close + wildcards < 0) return false;
        }

        // Both checks passed
        return true;
    }
};
