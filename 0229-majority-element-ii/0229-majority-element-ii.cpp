class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(int num :nums){
            mpp[num]++;
        }
        for(auto&pair : mpp){
            if(pair.second>nums.size()/3) ans.push_back(pair.first);
        }
        return ans;
    }
};