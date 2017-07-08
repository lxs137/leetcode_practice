class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if(strs.size() <= 0)
                return "";
            string longest = strs[0];
            for(auto &str: strs) {
                int j = 0, min_size = min(longest.size(), str.size());
                for(; j < min_size; j++) {
                    if(longest[j] != str[j]) {
                        break;
                    }
                }
                longest = longest.substr(0, j);
            }
            return longest;
        }
};
