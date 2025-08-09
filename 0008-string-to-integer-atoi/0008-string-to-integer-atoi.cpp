class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;  

        bool isNegative = false;
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            isNegative = s[i] == '-';
            i++;
        }

        long result = helper(s, i, 0);
        result = isNegative ? -result : result;

        // Clamp to 32-bit signed int range
        if (result < INT_MIN) return INT_MIN;
        if (result > INT_MAX) return INT_MAX;
        return (int)result;
    }

private:
    long helper(const string& s, int i, long acc) {
        if (i >= s.size() || !isdigit(s[i])) return acc;

        acc = acc * 10 + (s[i] - '0');
        if (acc > (long)INT_MAX + 1) return acc;  // early exit to prevent overflow

        return helper(s, i + 1, acc);
    }
};
