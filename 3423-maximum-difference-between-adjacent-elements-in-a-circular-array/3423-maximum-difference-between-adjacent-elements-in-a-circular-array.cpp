class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // Optional: handle small input
        
        int maxi = abs(nums[n - 1] - nums[0]); // circular diff
        for (int i = 0; i < n - 1; ++i) {
            maxi = max(maxi, abs(nums[i + 1] - nums[i]));
        }
        return maxi;
    }
};
