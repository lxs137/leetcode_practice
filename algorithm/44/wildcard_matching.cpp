class Solution {
public:
    map<pair<int, int>, tuple<bool, int, int>> solutions;
    bool isMatch(string s, string p) {
        if (s.size() == 0) {
            if (p.size() == 0) {
                return true;
            } else {
                for(char ch : p) {
                    if (ch != '*')
                        return false;
                }
                return true;
            }
        }
        bool isWildcard = false;
        int i = 0, j = 0, pN = p.size();
        while (j < pN) {
            if (p[j] == '*' && isWildcard) {
                j++;
            } else {
                if (p[j] == '*')
                    isWildcard = true;
                else
                    isWildcard = false;
                p[i] = p[j];
                i++;
                j++;
            }
        }
        p = p.substr(0, i);
        auto res = match(s, 0, p, 0);
        return get<0>(res);
    }
    tuple<bool, int, int> match(const string &s, int i, const string &p, int j) {
        auto hasExist = solutions.find(make_pair(i, j));
        if (hasExist == solutions.end()) {
            auto matchRes = tryMatch(s, i, p, j);
            solutions.emplace(make_pair(i, j), matchRes);
            return matchRes;
        } else {
            return hasExist->second;
        }
    }
    tuple<bool, int, int> tryMatch(const string &s, int i, const string &p, int j) {
        int sN = s.size(), pN = p.size();
        while (j < pN) {
            if (p[j] == '?') {
                i++;
                j++;
            } else if (p[j] >= 'a' && p[j] <= 'z') {
                if (s[i] == p[j]) {
                    i++;
                    j++;
                } else {
                    return make_tuple(false, i, j);
                }
            } else {
                int tempI = sN;
                tuple<bool, int, int> matchRes;
                while (tempI >= i) {
                    matchRes = match(s, tempI, p, j + 1);
                    if (get<0>(matchRes)) {
                        i = get<1>(matchRes);
                        j = get<2>(matchRes);
                        break;
                    } else {
                        tempI--;
                    }
                }
                if (!get<0>(matchRes))
                    return make_tuple(false, i, j);
            }
        }
        if (i == sN && j ==pN)
            return make_tuple(true, i, j);
        else
            return make_tuple(false, i, j);
    }
};