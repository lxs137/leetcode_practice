class Solution {
    public:
        string intToRoman(int num) {
            vector<int> digits;
            char romans[4][2] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'M'};
            string result("");
            while(num > 0) {
                digits.push_back(num % 10);
                num /= 10;
            }
            for(int i = 0, n = digits.size(); i < n; i++) {
                result.insert(0, digitToRoman(digits[i], romans[i], romans[(i + 1) % 4][0]));
            }
            return result;
        }
        string digitToRoman(int digit, char *roman, char next) {
            string res("");
            if(digit <= 3) {
                res.append(digit, roman[0]);
            }
            else if(digit <= 5) {
                res.append(5 - digit, roman[0]);
                res.append(1, roman[1]);
            }
            else if(digit <= 8) {
                res.append(1, roman[1]);
                res.append(digit - 5, roman[0]);
            }
            else {
                res.append(1, roman[0]);
                res.append(1, next);
            }
            return res;
        }
};
