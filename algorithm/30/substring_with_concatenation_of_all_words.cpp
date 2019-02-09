class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.size() == 0)
            return res;    
        int words_count = words.size(), word_len = words[0].length(), total_len = s.length(), sub_len = words_count * word_len;
        vector<string> temp_words;
        for(int i = 0, j = sub_len - 1; j < total_len; i++, j++) {
            temp_words.clear();
            for(int k = 0; k < sub_len; k += word_len) {
                temp_words.push_back(s.substr(i + k, word_len));
            }
            if(words_match(words, temp_words))
                res.push_back(i);
        }
        return res;
    }
    bool words_match(vector<string> &words1, vector<string> &words2) {
        for(string &word : words1) {
            auto res = find(words2.begin(), words2.end(), word);
            if(res == words2.end())
                return false;
            else 
                words2.erase(res);
        }
        return true;
    }
};