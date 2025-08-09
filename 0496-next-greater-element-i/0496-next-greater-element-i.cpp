class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while (j < nums2.size() && nums2[j] != nums1[i]) j++;

            int k = j + 1;
            while (k < nums2.size() && nums2[k] <= nums2[j]) k++;

            if (k < nums2.size()) nums1[i] = nums2[k];
            else nums1[i] = -1;
        }
        return nums1;
    }
};
