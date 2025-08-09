class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int goodIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) nums[goodIndex++]=nums[i];
        }
        for(int i=goodIndex;i<nums.size();i++){
            nums[i]=0;
        }
    }
};