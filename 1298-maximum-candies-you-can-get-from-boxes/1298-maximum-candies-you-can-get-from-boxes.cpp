class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> hasKey(n, false), hasBox(n, false), visited(n, false);
        queue<int> q;

        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) {
                q.push(box);
                visited[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int box = q.front(); q.pop();
            totalCandies += candies[box];

            // Gain keys
            for (int k : keys[box]) {
                if (!hasKey[k]) {
                    hasKey[k] = true;
                    // If we already have the box and haven’t visited it yet, open it
                    if (hasBox[k] && !visited[k] && status[k] == 0) {
                        status[k] = 1;
                        q.push(k);
                        visited[k] = true;
                    }
                }
            }

            // Gain contained boxes
            for (int b : containedBoxes[box]) {
                hasBox[b] = true;
                if (!visited[b]) {
                    if (status[b] == 1 || hasKey[b]) {
                        status[b] = 1;
                        q.push(b);
                        visited[b] = true;
                    }
                }
            }
        }

        return totalCandies;
    }
};
