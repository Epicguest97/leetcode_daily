class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> keyIndices;
        int n = nums.size();

        // Step 1: Find all indices where nums[i] == key
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyIndices.push_back(i);
            }
        }

        // Step 2: Mark all indices that are within k distance
        vector<bool> isKDist(n, false);
        for (int idx : keyIndices) {
            int start = max(0, idx - k);
            int end = min(n - 1, idx + k);
            for (int i = start; i <= end; ++i) {
                isKDist[i] = true;
            }
        }

        // Step 3: Collect result indices
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (isKDist[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
