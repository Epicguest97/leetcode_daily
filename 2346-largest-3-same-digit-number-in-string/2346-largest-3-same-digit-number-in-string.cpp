class Solution {
public:
    string largestGoodInteger(string num) {
        vector<int>maxis;
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1] && num[i]==num[i+2]){
                int digit=num[i]-'0';
                maxis.push_back(100*digit+10*digit+digit);
            }
        }
        if(maxis.size()==0)return "";
        string ans=to_string(*max_element(maxis.begin(),maxis.end()));
        if(ans=="0")return "000";
        return ans;
    }
};
