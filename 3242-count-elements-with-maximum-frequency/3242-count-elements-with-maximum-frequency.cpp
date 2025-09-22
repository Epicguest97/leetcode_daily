class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>hash;
        for(int num :nums)hash[num]++;
        int maxfreq=0;
        for(auto &p:hash){
            if(p.second>maxfreq)maxfreq=p.second;
        }
        int res=0;
        for(auto &p: hash){
            if(p.second==maxfreq)res+=maxfreq;
        }
        return res;
    }
};