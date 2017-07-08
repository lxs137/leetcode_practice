class Solution {
    public:
        int romanToInt(string s) {
            map<char, int> char_map;
            char_map['I'] = 1, char_map['V'] = 5, char_map['X'] = 10, char_map['L'] = 50, char_map['C'] = 100, char_map['D'] = 500, char_map['M'] = 1000;
            int res = 0;
            for(int i = 0, j = 0, n = s.size() - 1; i <= n; i++) {
                if(char_map[s[j]] >= char_map[s[i]]) {
                    res += char_map[s[i]];
                }
                else {
                    res -= 2 * char_map[s[j]];
                    res += char_map[s[i]];
                }
                j = i;
            }
            return res;
        }
};
