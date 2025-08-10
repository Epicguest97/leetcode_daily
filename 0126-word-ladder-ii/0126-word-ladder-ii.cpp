class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};
        dict.insert(beginWord);
        unordered_map<string, vector<string>> adj;
        for (auto &w1 : dict) {
            for (auto &w2 : dict) {
                if (isOneLetterDiff(w1, w2)) {
                    adj[w1].push_back(w2);
                }
            }
        }
        unordered_map<string, int> dist;
        for (auto &w : dict) dist[w] = INT_MAX;
        dist[beginWord] = 0;

        unordered_map<string, vector<string>> parents; 

        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            string u = q.front();
            q.pop();
            for (auto &v : adj[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    parents[v].clear();
                    parents[v].push_back(u);
                    q.push(v);
                } 
                else if (dist[v] == dist[u] + 1) {
                    parents[v].push_back(u);
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        dfs(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    bool isOneLetterDiff(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) diff++;
            if (diff > 1) return false;
        }
        return diff == 1;
    }

    void dfs(const string &word, const string &beginWord, 
             unordered_map<string, vector<string>> &parents,
             vector<string> &path, vector<vector<string>> &res) 
    {
        path.push_back(word);
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
        } else {
            for (auto &p : parents[word]) {
                dfs(p, beginWord, parents, path, res);
            }
        }
        path.pop_back();
    }
};
