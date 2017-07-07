class Solution {
    public:
        string longestPalindrome(string s) {
            if(s.size() == 0)
                return "";
            int max_len = 1, start_index = 0;
            for(int i = 0, n = s.size(); i < n; i++) {
                for(int j = n - 1; j > i; j--) {
                    if(is_palindrome(s, i, j)) {
                        if(max_len < (j - i + 1)) {
                            start_index = i;
                            max_len = j - i + 1;
                            if(max_len >= n - i - 1)
                                return s.substr(start_index, max_len);
                            break;
                        }
                    } 
                }
            }
            return s.substr(start_index, max_len);

        }
        bool is_palindrome(string &s, int i, int j) {
            while(i < j) {
                if(s[i] == s[j]) {
                    i++;
                    j--;
                }
                else
                    return false;
            }
            return true;
        }
};
