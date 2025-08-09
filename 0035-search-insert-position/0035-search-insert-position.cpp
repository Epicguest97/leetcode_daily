class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return bst(nums, target, 0, nums.size() - 1);
    }

private:
    int bst(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return left;  
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            return bst(nums, target, left, mid - 1);
        } else {
            return bst(nums, target, mid + 1, right);
        }
    }
};
