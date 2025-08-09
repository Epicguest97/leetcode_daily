class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word, result;
        istringstream iss(s);
        
        while (iss >> word) {
            st.push(word);
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }
        
        return result;
    }
};