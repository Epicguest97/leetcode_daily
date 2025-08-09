
class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        long long result = 0;
        int left = 0;
        std::unordered_map<int, int> freq_map;
        int min_val = nums[0], max_val = nums[0]; // Initialize min and max values

        for (int right = 0; right < nums.size(); ++right) {
            freq_map[nums[right]]++;  // Include nums[right] in the window
            min_val = std::min(min_val, nums[right]);
            max_val = std::max(max_val, nums[right]);
            
            // Check if the current window is valid
            while (max_val - min_val > 2) {
                // If invalid, shrink the window by moving `left`
                freq_map[nums[left]]--;
                if (freq_map[nums[left]] == 0) {
                    freq_map.erase(nums[left]);
                }
                left++;
                
                // Recalculate min and max values in the new window
                min_val = nums[left], max_val = nums[left];
                for (auto& p : freq_map) {
                    min_val = std::min(min_val, p.first);
                    max_val = std::max(max_val, p.first);
                }
            }
            
            // Add all valid subarrays ending at `right`
            result += (right - left + 1);
        }

        return result;
    }
};
