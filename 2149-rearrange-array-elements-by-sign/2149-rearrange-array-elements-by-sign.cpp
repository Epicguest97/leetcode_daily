class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int even=0,odd=1;
        vector<int>num1(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                num1[even]=nums[i];
                even+=2;
            }
            if(nums[i]<0){
                num1[odd]=nums[i];
                odd+=2;
            }
        }
        return num1;

    }
};