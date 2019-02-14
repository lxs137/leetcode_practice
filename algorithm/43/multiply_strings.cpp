class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string res = "0";
        int i = 0, len2 = num2.size();
        while (i < len2) {
            string tempStr = multiplyWithCh(num1, num2[len2 - i - 1]);
            tempStr.insert(tempStr.end(), i, '0');
            res = add(res, tempStr);
            i++;
        }
        return res;
    }
    string add(string num1, string num2) {
        if (num1 == "0")
            return num2;
        else if (num2 == "0")
            return num1;
        int i = 0, chIdx, len1 = num1.size(), len2 = num2.size(), 
            maxLen, overflow = 0;
        string res = "";
        if (len1 < len2) {
            maxLen = len2;
            num1.insert(num1.begin(), len2 - len1, '0');
        } else {
            maxLen = len1;
            num2.insert(num2.begin(), len1 - len2, '0');
        }
        while (i < maxLen) {
            chIdx = maxLen - i - 1;
            overflow += (num1[chIdx] - '0') + (num2[chIdx] - '0');
            if (overflow >= 10) {
                res.insert(res.begin(), to_string(overflow - 10)[0]);
                overflow = 1;
            } else {
                res.insert(res.begin(), to_string(overflow)[0]);
                overflow = 0;
            }
            i++;
        }
        if (overflow == 1)
            res.insert(res.begin(), 1, '1');
        return res;
    }
    string multiplyWithCh(string num, char ch) {
        if (ch == '0') {
            return "0";
        } else if (ch == '1') {
            return num;
        } else {
            int i = num.size() - 1, chVal = ch - '0', overflow = 0;
            string res = "";
            while (i >= 0) {
                overflow += (chVal * (num[i] - '0'));
                if (overflow >= 10) {
                    res.insert(res.begin(), to_string(overflow % 10)[0]);
                    overflow /= 10;
                } else {
                    res.insert(res.begin(), to_string(overflow)[0]);
                    overflow = 0;
                }
                i--;
            }
            if (overflow >= 1)
                res.insert(res.begin(), 1, to_string(overflow)[0]);
            return res;
        }
    }
};