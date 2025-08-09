class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)return word;
        int n = word.size();
        int maxLen = n - numFriends + 1;
        int bestStart = 0;

        for (int i = 1; i < n; ++i) {
            int j = 0;

            while (j < maxLen && i + j < n && word[bestStart + j] == word[i + j]) {
                j++;
            }

            if (j < maxLen && i + j < n && word[i + j] > word[bestStart + j]) {
                bestStart = i;
            }
        }

        return word.substr(bestStart, maxLen);
    }
};
