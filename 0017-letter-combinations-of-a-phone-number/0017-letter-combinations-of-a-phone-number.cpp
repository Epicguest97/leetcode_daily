class Solution {
public:
    void help(int n,string& digits,int idx,vector<string>&ans,string &str,map<int,string>&ma){
        if(idx==n){
            ans.push_back(str);
            return;
        }
        string strr = ma[digits[idx]-'0'];
        for(int i=0;i<strr.size();i++){
            str.push_back(strr[i]);
            help(n,digits,idx+1,ans,str,ma);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return{};
        map<int,string>ma;
        ma[2]="abc";
        ma[3]="def";
        ma[4]="ghi";
        ma[5]="jkl";
        ma[6]="mno";
        ma[7]="pqrs";
        ma[8]="tuv";
        ma[9]="wxyz";
        vector<string>ans;
        int n = digits.size();
        string str;
        help(n,digits,0,ans,str,ma);
        return ans;
    }
};