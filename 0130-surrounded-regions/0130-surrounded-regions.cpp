class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, m, n);
            if (board[m-1][j] == 'O') dfs(m-1, j, board, m, n);
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, m, n);
            if (board[i][n-1] == 'O') dfs(i, n-1, board, m, n);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'S') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

private:
    void dfs(int row, int col, vector<vector<char>>& board, int m, int n) {
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != 'O')
            return;

        board[row][col] = 'S'; 

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            dfs(row + dr[i], col + dc[i], board, m, n);
        }
    }
};
