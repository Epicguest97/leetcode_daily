class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi = INT_MIN;
        int maxia = INT_MIN;
        
        for (int i = 0; i < dimensions.size(); i++) {
            int diagonal = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            int area = dimensions[i][0] * dimensions[i][1];
            
            if (diagonal > maxi) {
                maxi = diagonal;
                maxia = area;
            } else if (diagonal == maxi) {
                maxia = max(maxia, area);
            }
        }
        return maxia;
    }
};
