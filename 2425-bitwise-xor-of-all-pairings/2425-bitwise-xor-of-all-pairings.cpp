class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        for (int num : nums1) xor1 ^= num;
        for (int num : nums2) xor2 ^= num;
        int m = nums1.size(), n = nums2.size();
        return (m % 2 ? xor2 : 0) ^ (n % 2 ? xor1 : 0);
    }
};
