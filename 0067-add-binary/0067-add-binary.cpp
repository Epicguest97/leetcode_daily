class Solution {
public:
    string addBinary(string a, string b) {
        while(a.size() < b.size()) a.insert(a.begin(), '0');
        while(b.size() < a.size()) b.insert(b.begin(), '0');
        string res;
        int carry=0;
        for(int i=b.size()-1;i>=0;i--){
            int bitA = a[i] - '0';
            int bitB = b[i] - '0';
            int sum = bitA + bitB + carry;
            res.insert(res.begin(), (sum % 2) + '0'); 
            carry = sum / 2; 
        }
        if(carry)res.insert(res.begin(),'1');
        return res;
    }
};