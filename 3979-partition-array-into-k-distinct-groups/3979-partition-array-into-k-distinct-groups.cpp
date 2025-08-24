class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return false;
        unordered_map<int,int>freq;
        for(int x: nums)freq[x]++;
        int groups=n/k;
        for(auto &p : freq){
            if(p.second>groups)return false;
        }
        return true;
    }
};