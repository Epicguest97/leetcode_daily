class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lastzero=-1;
        int left=0;
        int maxi=0;
        for(int right;right<nums.size();right++){
            if(nums[right]==0){
                left=lastzero+1;
                lastzero=right;
            }
            maxi=max(maxi,right-left);
        }
        return maxi;
    }
};
