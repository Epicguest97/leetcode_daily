#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                } else {
                    if (i > 0 && res[i-1][j] != INT_MAX)
                        res[i][j] = min(res[i][j], res[i-1][j] + 1);
                    if (j > 0 && res[i][j-1] != INT_MAX)
                        res[i][j] = min(res[i][j], res[i][j-1] + 1);
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1 && res[i+1][j] != INT_MAX)
                    res[i][j] = min(res[i][j], res[i+1][j] + 1);
                if (j < n - 1 && res[i][j+1] != INT_MAX)
                    res[i][j] = min(res[i][j], res[i][j+1] + 1);
            }
        }

        return res;
    }
};
