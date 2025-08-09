class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>delta(nums.size(),0);
        for(auto&pair : queries){
            delta[pair[0]]--;
            if(pair[1]+1<nums.size()) delta[pair[1]+1]++;
        }
        int x=0;
        for(int i=0;i<nums.size();i++){
            x+=delta[i];
            nums[i]+=x;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0) return false;
        }
        return true;
    }
};