// class Solution {
// public:
//     string convert(string s, int numRows) {
//         string s1 = "";
//         for (int i = 0; i < numRows; i++) {
//             int temp = i;
//             if (i % 2 == 0) {
//                 while (temp <= s.size() - 1) {
//                     s1 += s[temp];
//                     temp += numRows + (numRows / 2);
//                 }
//             } else {
//                 while (temp <= s.size() - 1) {
//                     s1 += s[temp];
//                     temp += (numRows - i);
//                 }
//             }
//         }
//         return s1;
//     }
// };
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        
        vector<string> rows(min(numRows, int(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currentRow] += c;
            if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }

        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};
