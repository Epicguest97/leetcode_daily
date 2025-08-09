class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Step 1: Count frequency of characters
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Use a max-heap to prioritize largest lexicographical characters
        priority_queue<pair<char, int>> maxHeap; // <character, frequency>
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                maxHeap.push({char('a' + i), freq[i]});
            }
        }

        string result;
        while (!maxHeap.empty()) {
            auto [ch, count] = maxHeap.top();
            maxHeap.pop();

            int useCount = min(count, repeatLimit); // Use up to repeatLimit of current char
            result.append(useCount, ch);
            count -= useCount;

            if (count > 0) { // If we have more of this character remaining
                if (maxHeap.empty()) break; // If no smaller character exists, stop
                
                // Step 3: Add one occurrence of the next largest character
                auto [nextCh, nextCount] = maxHeap.top();
                maxHeap.pop();
                result.push_back(nextCh);
                nextCount--;

                // Push updated counts back into the heap
                if (nextCount > 0) {
                    maxHeap.push({nextCh, nextCount});
                }
                maxHeap.push({ch, count}); // Reinsert the original char with remaining count
            }
        }

        return result;
    }
};
