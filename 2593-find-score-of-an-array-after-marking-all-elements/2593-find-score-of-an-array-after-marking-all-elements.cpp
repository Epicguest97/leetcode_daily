class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<bool> marked(n, false); 
        
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        

        for (int i = 0; i < n; ++i) {
            minHeap.push({nums[i], i});
        }
        
        while (!minHeap.empty()) {
            
            int value = minHeap.top().first;
            int index = minHeap.top().second;
            minHeap.pop();
            
            
            if (marked[index]) {
                continue;
            }
            
            
            marked[index] = true;
            score += value;
            
            
            if (index > 0) {
                marked[index - 1] = true;
            }
            
            if (index < n - 1) {
                marked[index + 1] = true;
            }
        }
        
        return score;
    }
};