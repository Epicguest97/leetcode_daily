class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a max heap using a priority queue
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        // Perform k operations
        for (int i = 0; i < k; i++) {
            int maxVal = maxHeap.top();  // Extract the maximum value
            maxHeap.pop();              // Remove it from the heap
            maxHeap.push(floor(sqrt(maxVal))); // Push the modified value back into the heap
        }

        // Sum the remaining elements in the heap
        long long sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }

        return sum;
    }
};
