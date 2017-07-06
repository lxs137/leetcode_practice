class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        map<char, int> answer;
        for(int i = 0, n = s.length(); i < n; i++) {
            auto search = answer.find(s[i]);
            if(!answer.empty() && search != answer.end()) {
                max_length = (answer.size() > max_length ? answer.size() : max_length);
                answer.clear();
                i = ++(search->second);
                answer[s[i]] = i;
            }
            else {
                answer[s[i]] = i;
            }
        }
        return answer.size() > max_length ? answer.size() : max_length;
    }
};