class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=*min_element(bloomDay.begin(),bloomDay.end());
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        long long total=1LL*m*k;
        if (total > bloomDay.size()) return -1;
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(canmake(bloomDay,m,k,mid))right=mid;
            else left=mid+1;
        }
        return left;
    }
private:
    bool canmake(vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0, flowers = 0;
        for (int d : bloomDay) {
            if (d <= day) {   
                flowers++;
                if (flowers == k) {  
                    bouquets++;
                    flowers = 0;     
                }
            } else {
                flowers = 0; 
            }
        }
        return bouquets >= m;
    }
};