class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        if(find(wordList.begin(), wordList.end(), beginWord) == wordList.end())
            wordList.push_back(beginWord);

        unordered_map<string, vector<string>> adj;
        for(int i = 0; i < wordList.size(); i++) {
            for(int j = i + 1; j < wordList.size(); j++) {
                if(isOneLetterDiff(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while(!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(auto &nei : adj[word]) {
                if(!visited.count(nei)) {
                    visited.insert(nei);
                    q.push({nei, steps + 1});
                }
            }
        }
        return 0;
    }

private:
    bool isOneLetterDiff(const string &a, const string &b) {
        if(a.size() != b.size()) return false;
        int diff = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) diff++;
            if(diff > 1) return false;
        }
        return diff == 1;
    }
};
