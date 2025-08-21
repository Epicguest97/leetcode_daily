class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int mid;
        while(left<right){
            mid=(left+right)/2;
            if(canfinish(mid,piles,h))right=mid;
            else left=mid+1;
        }
        return left;
    }
private:
    bool canfinish(int mid,vector<int>&piles,int h){
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i])/mid;
            if(piles[i]%mid!=0)sum++;
        }
        return sum<=h;
    }

};