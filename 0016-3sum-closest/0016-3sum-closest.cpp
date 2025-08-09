class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int close = nums[0] + nums[1] + nums[2];  // Initialize with the first three elements
        
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicate elements

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == target) return sum;  // If exact target is found
                
                if (abs(sum - target) < abs(close - target)) {
                    close = sum;  // Update closest sum
                }

                if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return close;
    }
};
;