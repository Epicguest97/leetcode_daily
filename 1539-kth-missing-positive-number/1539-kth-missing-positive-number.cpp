class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0;
        int current = 1;
        int i = 0;

        while (true) {
            if (i < arr.size() && arr[i] == current) {
                i++;
            } else {
                missingCount++;
                if (missingCount == k) return current;
            }
            current++;
        }
    }
};
