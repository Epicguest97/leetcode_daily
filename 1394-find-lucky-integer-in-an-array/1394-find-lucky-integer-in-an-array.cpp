class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi=INT_MIN;
        for(int num : arr){
            if(num>maxi)maxi=num;
        }
        vector<int>hash(maxi+1,0);
        for(int num : arr){
            hash[num]++;
        }
        for(int i=hash.size()-1;i>=1;i--){
            if(i==hash[i])return i;
        }
        return -1;
    }
};