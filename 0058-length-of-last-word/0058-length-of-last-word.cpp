class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==' ' && isalpha(s[i+1]))count=0;
            if(isalpha(s[i]) && isalpha(s[i+1]))count++;
        }
        return count+1;
    }
};