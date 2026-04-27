class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2)
            return x * half * half;
        else
            return half * half;
    }

    double myPow(double x, int n) {
        long long pow = n;

        if (pow < 0) {
            x = 1 / x;
            pow = -pow;  
        }

        return power(x, pow);
    }
};