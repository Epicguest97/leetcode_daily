class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end()); 
        int right = accumulate(weights.begin(), weights.end(), 0); 
        int mid;

        while (left < right) {
            mid = left + (right - left) / 2;
            if (okay(weights, days, mid)) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }

private:
    bool okay(vector<int>& weights, int days, int capacity) {
        int d = 1; 
        int current = 0;

        for (int w : weights) {
            if (current + w > capacity) {
                d++;           
                current = 0;   
            }
            current += w;
        }
        return d <= days;
    }
};
