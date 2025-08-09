class Solution {
public:
    int differenceOfSums(int n, int m) {
        int last = n - (n % m);
        int count = (last - m) / m + 1; 
        int num2 = count * (m + last) / 2; 
        int total = n * (n + 1) / 2;
        int num1 = total - num2;
        return num1 - num2;
    }
};
