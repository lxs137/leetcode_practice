class Solution {
    public:
        int reverse(int x) {
            double d = pow(2, 31);
            if(x > d - 1 || x < -d || x == 0)
                return 0;
            int result = 0, sign = (x > 0 ? 1 : -1);
            x  = abs(x);
            while(x > 0) {
                if(result > (int)((d - 1)/10))
                    return 0;
                result *= 10;
                result += x % 10;
                x /= 10;
            }
            return result * sign;
        }
};
