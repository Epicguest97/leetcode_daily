class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s;
        string minStr = s;

        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char &c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }

        char toReplaceMin = s[0];
        for (char &c : minStr) {
            if (c == toReplaceMin) c = '0';
        }

        return stoi(maxStr) - stoi(minStr);
    }
};
