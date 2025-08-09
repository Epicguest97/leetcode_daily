class Solution {
public:
    string clearStars(string s) {
        vector<char> stack;
        unordered_map<char, vector<int>> charIndices;
        priority_queue<char, vector<char>, greater<char>> minHeap;

        for (char c : s) {
            if (c != '*') {
                stack.push_back(c);
                charIndices[c].push_back(stack.size() - 1);
                minHeap.push(c);
            } else {
                if (stack.empty()) {
                    continue;
                }
                char min_char = minHeap.top();
                while (charIndices[min_char].empty()) {
                    minHeap.pop();
                    min_char = minHeap.top();
                }
                int index = charIndices[min_char].back();
                charIndices[min_char].pop_back();
                stack[index] = '\0'; 
                minHeap.pop(); 
            }
        }

        string result;
        for (char c : stack) {
            if (c != '\0') {
                result += c;
            }
        }
        return result;
    }
};