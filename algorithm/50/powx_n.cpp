class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (n == 1) {
            return x;
        } else if (n == -1) {
            return 1 / x;
        } else if (x - 1 < 1e-10 && x - 1 > -1e-10) {
            return 1.0;
        }
        double res = 1.0, temp;
        if (n > 0) {
            temp = x;
            while (n >= 1) {
                while (n % 2 == 0 && n >= 1) {
                    n /= 2;
                    temp *= temp;
                }
                if (n % 2 == 1) {
                    res *= temp;
                    n--;
                }
            }
        } else {
            temp = 1 / x;
            while (n <= -1) {
                while (n % 2 == 0 && n <= -1) {
                    n /= 2;
                    temp *= temp;
                }
                if (n % 2 == 1 || n % 2 == -1) {
                    res *= temp;
                    n++;
                }
            }
        }
        return res;
    }
};