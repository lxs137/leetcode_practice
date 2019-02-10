class Solution {
public:
    // <matched_len, matched_end_idx>
    vector<pair<int, int>> matched_pairs;
    pair<int, int> matched_pair;
    int longestValidParentheses(string s) {
        vector<pair<char, int>> matches;
        for(int i = 0; i < s.length(); i++) {
            int matched_res = try_match(matches, s[i], i);
            if (matched_res == -2) {
                store_prev_matched_pair();
            } else if (matched_res >= 0) {
                matched_pair.first = i - matched_res + 1;
                matched_pair.second = i;
                store_prev_matched_pair();
            }
        }
        store_prev_matched_pair();
        int max_matched_len = 0;
        for(auto item = matched_pairs.rbegin(); item != matched_pairs.rend(); item++) {
            auto next_item = next(item, 1);
            if (next_item != matched_pairs.rend()) {
                if (item->second - item->first == next_item->second) {
                    next_item->first += item->first;
                    next_item->second = item->second;
                } else if (next_item->second - next_item->first >= item->second - item->first) {
                    next_item->first = item->first;
                    next_item->second = item->second;
                }
            }
            if (item->first > max_matched_len) {
                max_matched_len = item->first;
            }
        }
        return max_matched_len;
    }
    void store_prev_matched_pair() {
        if (matched_pair.first == 0)
            return;
        if (matched_pairs.empty()) {
            matched_pairs.emplace_back(matched_pair.first, matched_pair.second);
        } else {
            auto &last_matched = matched_pairs.back();
            if ((last_matched.second - last_matched.first) >= (matched_pair.second - matched_pair.first)) {
                last_matched.first = matched_pair.first;
                last_matched.second = matched_pair.second;
            } else {
                matched_pairs.emplace_back(matched_pair.first, matched_pair.second);
            }
        }
        matched_pair.first = 0;
        matched_pair.second = 0;
    }
    // -2: not match
    // -1: probabaly match in the future
    // >=0: matched start idx
    int try_match(vector<pair<char, int>> &matches, const char ch, int idx) {
        if (matches.empty()) {
            if (ch == ')') {
                return -2;
            } else {
                matches.emplace_back(ch, idx);
                return -1;
            }
        }
        auto &top_pair = matches.back();
        if (top_pair.first == '(' && ch == ')') {
            matches.pop_back();
            return top_pair.second;
        } else if (top_pair.first == '(' && ch == '(') {
            matches.emplace_back(ch, idx);
            return -1;
        } else {
            matches.clear();
            return -2;
        }
    }
};