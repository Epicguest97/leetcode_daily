class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        for (int i = 0; i < s.size(); i += k) {
            string temp = s.substr(i, k);
            while (temp.size() < k) {
                temp += fill;
            }
            res.push_back(temp);
        }
        return res;
    }
};
