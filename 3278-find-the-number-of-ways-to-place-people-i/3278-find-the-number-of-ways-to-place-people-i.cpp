class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int cnt = 0;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                if (points[i][0] <= points[j][0] && points[i][1] >= points[j][1]) {
                    if (nobetween(i, j, points)) cnt++;
                }
            }
        }
        return cnt;
    }
private:
    bool nobetween(int i, int j, const vector<vector<int>>& points) {
        for (int a = 0; a < points.size(); a++) {
            if (a == i || a == j) continue;
            bool row = (points[a][0] >= points[i][0] && points[a][0] <= points[j][0]);
            bool col = (points[a][1] <= points[i][1] && points[a][1] >= points[j][1]);
            if (row && col) return false;
        }
        return true;
    }
};
