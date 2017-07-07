NT_MAX 2147483647
#define INT_MIN -2147483648
class Solution {
    public:
        int myAtoi(string str) {
            str = ltrim(rtrim(str));
            int result = 0, sign = (str[0] == '-' ? -1 : 1);
            if(str[0] == '+' || str[0] == '-')
                str = str.substr(1);
            for(int i = 0, n = str.size(); i < n; i++) {
                if(str[i] >= '0' && str[i] <= '9') {
                    if(result > INT_MAX/10)
                        return (sign > 0 ? INT_MAX : INT_MIN);
                    result *= 10;
                    result += str[i] - '0';
                }
                else
                    break;
            }
            if(result < 0 && sign > 0)
                return INT_MAX;
            if(result < 0 && sign < 0)
                return INT_MIN;
            return result * sign;
        }
        string ltrim(string s)
        {
            string result;
            bool sign = true;
            for(int i = 0, n = s.size(); i < n; i++) {
                if(sign && (s[i] == ' ' || s[i] == '\n' || s[i] == '\r')) 
                    continue;                
                result.append(1, s[i]);
                sign = false;                
            }
            return result;
        }
        string rtrim(string s)
        {
            bool sign = true;
            int j = s.size() - 1;
            for(int i = s.size() - 1; i >= 0; i--) {
                if(sign && (s[i] == ' ' || s[i] == '\n' || s[i] == '\r')) 
                    continue;                
                s[j] = s[i];
                j--;
                sign = false;                
            }
            return s.substr(j + 1);        
        }
};
