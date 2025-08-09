class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), greater<int>()); 
        unordered_map<int, int> freq;

        for (int i = 0; i < k; ++i) {
            freq[temp[i]]++;
        }

        vector<int> result;
        for (int num : nums) {
            if (freq[num] > 0) {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
