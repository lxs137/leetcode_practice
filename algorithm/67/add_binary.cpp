#define CHAR_PLUS(a, b) (a + b - '0' - '0')

class Solution {
 public:
  string addBinary(string a, string b) {
    if (a.size() < b.size()) {
      string temp(b.size() - a.size(), '0');
      a.insert(a.begin(), temp.begin(), temp.end());
    } else {
      string temp(a.size() - b.size(), '0');
      b.insert(b.begin(), temp.begin(), temp.end());
    }
    vector<char> res;
    int flag = '0';
    for (auto aI = a.rbegin(), bI = b.rbegin(); aI != a.rend(); aI++, bI++) {
      if (CHAR_PLUS(*aI, *bI) == 2) {
        res.push_back(flag);
        flag = '1';
      } else if (CHAR_PLUS(*aI, *bI) == 1) {
        res.push_back(flag == '0' ? '1' : '0');
      } else {
        res.push_back(flag);
        flag = '0';
      }
    }
    if (flag == '1') {
      res.push_back('1');
    }

    string s = "";
    for (auto item = res.rbegin(); item != res.rend(); item++) {
      s += *item;
    }
    return s;
  }
};
