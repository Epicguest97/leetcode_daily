class Solution {
public:
    string reverseVowels(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i]))st.push(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i]=st.top();
                st.pop();
            }
        }
        return s;
    }
private:
    bool isvowel(char ch){
        string v="aeiouAEIOU";
        return v.find(ch)!=string::npos;
    }
};