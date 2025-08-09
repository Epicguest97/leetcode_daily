class Solution {
public:
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  
        vector<int> temp1(nums.begin(), nums.end() - 1);  
        vector<int> temp2(nums.begin() + 1, nums.end());  
        return max(robLinear(temp1), robLinear(temp2));
    }
};
