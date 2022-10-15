class Solution {
    public:
        bool isHappy(int n) {
            if(n == 1) return true;
            if(n == 0) return false;

            int repeated = n;
            while(repeated != 1 && repeated != 4) {
                int sum = 0;
                while(n > 0) {
                    int digit = n % 10;
                    sum += digit * digit;
                    n /= 10;
                }

                if(sum == 1) return true;
                if(sum == 89) return false;
                n = sum;
            }

            return false;
        }
};