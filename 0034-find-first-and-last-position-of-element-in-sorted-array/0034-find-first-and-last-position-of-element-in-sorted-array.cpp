class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left= findleft(nums,target);
        int right =findright(nums,target);
        return {left,right};
    }
private:
    int findleft(vector<int>&nums,int target){
        int left=0,result= -1,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else{
                if(nums[mid]==target) result = mid;
                right=mid-1;
            }
        }
        return result;
    }
    int findright(vector<int>&nums,int target){
        int left=0,result= -1,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>target) right=mid-1;
            else{
                if(nums[mid]==target) result = mid;
                left=mid+1;
            }
        }
        return result;
    }
};