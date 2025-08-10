class Solution {
public:
    bool reorderedPowerOf2(int n) {
        auto count =[](int x){
            string s=to_string(x);
            sort(s.begin(),s.end());
            return s;
        };
        string target=count(n);
        for(int i=0;i<31;i++){
            if(count(1<<i)==target)return true;
        }
        return false;
    }
};