class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        // Pass 1: Left to right
        int balls = 0, operations = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }

        // Pass 2: Right to left
        balls = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += operations;
            balls += (boxes[i] == '1') ? 1 : 0;
            operations += balls;
        }

        return answer;
    }
};
