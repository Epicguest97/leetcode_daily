class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!check(board[i])) return false;
        }
        for (int j = 0; j < 9; j++) {
            vector<char> col;
            for (int i = 0; i < 9; i++) {
                col.push_back(board[i][j]);
            }
            if (!check(col)) return false;
        }
        for (int bi = 0; bi < 9; bi += 3) {
            for (int bj = 0; bj < 9; bj += 3) {
                vector<char> box;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        box.push_back(board[bi+i][bj+j]);
                    }
                }
                if (!check(box)) return false;
            }
        }
        return true;
    }

private:
    bool check(vector<char>& s) {
        vector<int> seen(10, 0);
        for (char c : s) {
            if (c == '.') continue;
            int num = c - '0';
            if (num < 1 || num > 9) return false;
            if (seen[num]) return false;
            seen[num] = 1;
        }
        return true;
    }
};
