class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(nums,0,temp,result);
        return result;
    }
private:
    void backtrack(vector<int>&nums,int index,vector<int>&temp,vector<vector<int>>&result){
        result.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(nums,i+1,temp,result);
            temp.pop_back();
        }
    }
};