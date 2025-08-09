class Solution {
public:
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return graph;
    }
    
    vector<int> bfsDistances(int n, vector<vector<int>>& graph, int start) {
        vector<int> dist(n, -1);
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = (int)edges1.size() + 1;
        int m = (int)edges2.size() + 1;
        
        auto graph1 = buildGraph(n, edges1);
        auto graph2 = buildGraph(m, edges2);
        
        // Compute all-pairs distances for tree1
        vector<vector<int>> dist1(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            dist1[i] = bfsDistances(n, graph1, i);
        }
        
        // Compute all-pairs distances for tree2
        vector<vector<int>> dist2(m, vector<int>(m, -1));
        for (int j = 0; j < m; j++) {
            dist2[j] = bfsDistances(m, graph2, j);
        }
        
        // Count how many nodes are within distance k in tree1 for each node
        vector<int> count_tree1(n, 0);
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int x = 0; x < n; x++) {
                if (dist1[i][x] != -1 && dist1[i][x] <= k) cnt++;
            }
            count_tree1[i] = cnt;
        }
        
        // Count how many nodes are within distance k-1 in tree2 for each node
        vector<int> count_tree2(m, 0);
        if (k > 0) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int y = 0; y < m; y++) {
                    if (dist2[j][y] != -1 && dist2[j][y] <= k - 1) cnt++;
                }
                count_tree2[j] = cnt;
            }
        } else {
            // k = 0 means no cross-tree nodes except itself
            // so count_tree2 stays 0
        }
        
        // For each node in tree1, find max possible sum by connecting to any node in tree2
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            int max_target = 0;
            for (int j = 0; j < m; j++) {
                int total = count_tree1[i] + count_tree2[j];
                if (total > max_target) {
                    max_target = total;
                }
            }
            answer[i] = max_target;
        }
        
        return answer;
    }
};
