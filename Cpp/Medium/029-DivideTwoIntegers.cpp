class Solution {
    public:
        int divide(int dividend, int divisor) {
            int quotient = 0;

            if(divisor == 0) return INT_MAX;
            if(dividend == INT_MIN && divisor == -1) return INT_MAX;
            if(dividend == INT_MIN && divisor == 1) return INT_MIN;
            if(dividend == 0) return 0;
            if(divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;

            bool isNegative = (dividend < 0) ^ (divisor < 0);

            long long dividendLL = abs((long long)dividend);
            long long divisorLL = abs((long long)divisor);

            while(dividendLL >= divisorLL) {
                long long temp = divisorLL;
                long long multiple = 1;

                while(dividendLL >= (temp << 1)) {
                    temp <<= 1;
                    multiple <<= 1;
                }

                dividendLL -= temp;
                quotient += multiple;
            }

            return isNegative ? -quotient : quotient;
        }
};