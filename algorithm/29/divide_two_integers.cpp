class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        else if (divisor == 1) 
            return dividend;
        else if (divisor == -1) {
            if(dividend == -2147483648)
                return 2147483647;
            else
                return -dividend;
        }
        bool is_negative = is_opposite(dividend, divisor);
        int result = 0, temp;        
        while(dividend != 0) {
            if(is_negative) {
                temp = dividend + divisor;
            } else {
                temp = dividend - divisor;
            }
            if(is_opposite(temp, dividend)) {
                break;
            } else {
                dividend = temp;
                result++;
            }
        }
        return is_negative ? -result : result;
    }
    bool is_opposite(int a, int b ) {
        return ((a > 0 && b < 0) || (a < 0 && b > 0)) ? true : false;
    }
};