class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(const auto& interval : intervals){
            if(merged.empty() || merged.back()[1] < interval[0]){
                merged.push_back(interval);
            }
            else{
                merged.back()[1]=max(interval[1],merged.back()[1]);
            }
        }
        return merged;
    }
};