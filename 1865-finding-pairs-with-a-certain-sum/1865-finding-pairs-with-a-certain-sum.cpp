class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    
    void add(int index, int val) {
        int old_val = nums2[index];
        int new_val = old_val + val;
        freq2[old_val]--;
        if (freq2[old_val] == 0) {
            freq2.erase(old_val);
        }
        freq2[new_val]++;
        
        nums2[index] = new_val;
    }
    
    int count(int tot) {
        int result = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freq2.find(complement) != freq2.end()) {
                result += freq2[complement];
            }
        }
        return result;
    }
};
