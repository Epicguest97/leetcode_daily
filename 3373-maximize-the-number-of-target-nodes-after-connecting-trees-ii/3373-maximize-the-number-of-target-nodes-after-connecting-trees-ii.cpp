class Solution {
public:
    void bfs(const vector<vector<int>>& tree, vector<int>& depth, int& even, int& odd) {
        queue<int> q;
        q.push(0);
        depth[0] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            if (depth[node] % 2 == 0) even++;
            else odd++;

            for (int nei : tree[node]) {
                if (depth[nei] == -1) {
                    depth[nei] = depth[node] + 1;
                    q.push(nei);
                }
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        // BFS to calculate depth parity
        vector<int> depth1(n, -1), depth2(m, -1);
        int even1 = 0, odd1 = 0, even2 = 0, odd2 = 0;

        bfs(tree1, depth1, even1, odd1);
        bfs(tree2, depth2, even2, odd2);

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (depth1[i] % 2 == 0) {
                // Connect to a node with even depth in tree2: even path in tree2 stays even
                result[i] = max(even1 + even2, even1 + odd2);
            } else {
                // Connect to a node with odd depth in tree2: odd path in tree2 becomes even
                result[i] = max(odd1 + odd2, odd1 + even2);
            }
        }

        return result;
    }
};
