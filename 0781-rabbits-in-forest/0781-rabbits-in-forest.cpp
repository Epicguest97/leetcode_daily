class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int c = count(answers.begin(), answers.end(), 0); // count zeros
        unordered_map<int, int> freq;

        for (int x : answers) {
            if (x != 0) freq[x]++;
        }

        int val = 0;
        int length = 0;

        for (auto& [k, f] : freq) {
            int groupSize = k + 1;
            int numGroups = (f + k) / groupSize;  // ceiling division
            val += k * numGroups;                // the 'others'
            length += numGroups;                 // the original rabbit (saying it)
        }

        return c + val + length; // zeros + all implied rabbits + the ones saying it
    }
};
