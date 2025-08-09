class Solution {
public:
    int maxEvents(std::vector<std::vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int i = 0, res = 0, day = 0;
        int n = events.size();
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[i][0];
            }
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                ++i;
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                minHeap.pop();
                ++res;
                ++day;
            }
        }

        return res;
    }
};
