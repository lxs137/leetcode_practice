class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        if (s.empty())
            return len;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (*it == ' ') {
                if (len != 0) {
                    break;
                }
            } else {
                len++;
            }
        }
        return len;
    }
};