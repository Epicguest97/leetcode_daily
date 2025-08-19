class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sizes;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                if (count > 0) sizes.push_back(count);
                count = 0;
            }
        }
        if (count > 0) sizes.push_back(count); 

        long long res = 0;
        for (int len : sizes) {
            res += (1LL * len * (len + 1)) / 2; 
        }
        return res;
    }
};
