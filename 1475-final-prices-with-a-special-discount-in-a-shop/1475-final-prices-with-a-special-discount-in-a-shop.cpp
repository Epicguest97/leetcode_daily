class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(prices.begin(), prices.end()); // Initialize result with the original prices
        stack<int> stk; // Stack to store indices of items
        
        // Traverse the prices array
        for (int i = 0; i < n; i++) {
            // Apply the discount for items in the stack
            while (!stk.empty() && prices[stk.top()] >= prices[i]) {
                int index = stk.top();
                stk.pop();
                result[index] -= prices[i]; // Apply discount
            }
            stk.push(i); // Push current index onto the stack
        }
        
        return result;
    }
};
