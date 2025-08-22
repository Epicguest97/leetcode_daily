class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (okay(nums, threshold, mid)) {
                right = mid;  
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }

private:
    bool okay(const vector<int>& nums, int threshold, int mid) {
        long long sum = 0; 
        for (int num : nums) {
            sum += num/ mid; 
            if(num%mid!=0)sum++;
            if (sum > threshold) return false; 
        }
        return sum <= threshold;
    }
};
