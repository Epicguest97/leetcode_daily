
using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLength = pref.size();
        
        for (const string& word : words) {
            // Check if the word starts with the prefix
            if (word.substr(0, prefLength) == pref) {
                ++count;
            }
        }
        
        return count;
    }
};
