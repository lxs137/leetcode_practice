class Solution {
public:
    int strStr(string haystack, string needle) {
        int src_len = haystack.length(), dst_len = needle.length();
        if(dst_len == 0)
            return 0;
        else if(src_len == 0)
            return -1;
        for(int i = 0, j = 0; i < src_len; i++) {
            if(needle.at(j) == haystack.at(i)) {
                if(j == dst_len - 1) {
                    return i - j;
                } else {
                    j++;
                }
            } else {
                if(j > 0) {
                    i = i - j;
                }
                j = 0;
            }
        }
        return -1;
    }
};