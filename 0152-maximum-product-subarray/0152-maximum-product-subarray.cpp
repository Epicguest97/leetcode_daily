class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0], currMin = nums[0], result = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int tempMax = currMax;
            currMax = max({nums[i], nums[i] * currMax, nums[i] * currMin});
            currMin = min({nums[i], nums[i] * tempMax, nums[i] * currMin});
            result = max(result, currMax);
        }
        
        return result;
    }
};
