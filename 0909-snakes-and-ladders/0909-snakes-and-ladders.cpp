class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Converts a square number to (row, col) in the board
        auto get_coords = [n](int s) {
            int quot = (s - 1) / n;
            int rem = (s - 1) % n;
            int row = n - 1 - quot;
            int col = (quot % 2 == 0) ? rem : n - 1 - rem;
            return make_pair(row, col);
        };
        
        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // {square, steps}
        q.push({1, 0});
        visited[1] = true;
        
        while (!q.empty()) {
            auto [s, steps] = q.front(); q.pop();
            
            for (int i = 1; i <= 6; ++i) {
                int next = s + i;
                if (next > n * n) continue;
                
                auto [r, c] = get_coords(next);
                if (board[r][c] != -1)
                    next = board[r][c];
                
                if (next == n * n)
                    return steps + 1;
                
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, steps + 1});
                }
            }
        }
        
        return -1; // not reachable
    }
};
