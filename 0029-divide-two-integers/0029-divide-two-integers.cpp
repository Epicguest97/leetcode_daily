class Solution {
public:
    
    int divide(int dividend, int divisor) {
        if (divisor==1) return dividend;
        // Handle overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to positive values
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        int quotient = 0;

        // Subtract divisor from dividend using bitwise shifts
        while (absDividend >= absDivisor) {
            long long temp = absDivisor, multiple = 1;
            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            absDividend -= temp;
            quotient += multiple;
        }

        // Apply the sign to the quotient
        return negative ? -quotient : quotient;
    }
};
