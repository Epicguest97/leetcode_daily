class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the improvement in pass ratio
        auto improvement = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max-heap to store pairs of improvement and class info
        priority_queue<pair<double, pair<int, int>>> maxHeap;
        
        // Initialize the heap with all classes
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            maxHeap.push({improvement(pass, total), {pass, total}});
        }
        
        // Assign extra students
        while (extraStudents > 0) {
            // Pop the class with the highest improvement
            auto [delta, cls] = maxHeap.top();
            maxHeap.pop();
            int pass = cls.first, total = cls.second;
            
            // Add an extra student to this class
            pass++;
            total++;
            
            // Push the updated class back into the heap
            maxHeap.push({improvement(pass, total), {pass, total}});
            
            // Decrease the count of extra students
            extraStudents--;
        }
        
        // Calculate the final average pass ratio
        double totalAverage = 0.0;
        while (!maxHeap.empty()) {
            auto [_, cls] = maxHeap.top();
            maxHeap.pop();
            int pass = cls.first, total = cls.second;
            totalAverage += (double)pass / total;
        }
        
        // Return the average over all classes
        return totalAverage / classes.size();
    }
};
