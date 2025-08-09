class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long current = 0;
        long long minVal = 0, maxVal = 0;

        for (int diff : differences) {
            current += diff;
            minVal = min(minVal, current);
            maxVal = max(maxVal, current);
        }

        long long minStart= lower-minVal;
        long long maxStart= upper-maxVal;

        return max(0LL,maxStart-minStart+1);
    }
};
