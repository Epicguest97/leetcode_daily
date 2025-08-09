class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suffixMin(n);
        suffixMin[n - 1] = s[n - 1];

        // Build suffixMin: min character from i to end
        for (int i = n - 2; i >= 0; --i) {
            suffixMin[i] = min(s[i], suffixMin[i + 1]);
        }

        string result;
        stack<char> t;
        
        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // Pop from t to result while possible
            while (!t.empty() && (i == n - 1 || t.top() <= suffixMin[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        // Empty remaining stack
        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
