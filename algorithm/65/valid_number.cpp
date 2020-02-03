#define IS_NUMBER(c) (c >= '0' && c <= '9')

class Solution {
 public:
  bool isNumber(string s) {
    // trim
    int len = s.size();
    while (s[len - 1] == ' ') {
      s.erase(--len, 1);
    }
    while (s[0] == ' ') {
      s.erase(0, 1);
    }

    int i = 0;
    for (; i < len; i++) {
      if (s[i] == 'e') {
        break;
      }
    }

    if (i == len) {
      return isFloat(s);
    } else if (i == len - 1) {
      return false;
    } else {
      return isFloat(s.substr(0, i)) && isInteger(s.substr(i + 1));
    }
  }

  bool parseAbsolute(string &s) {
    if (s.size() == 0) {
      return false;
    }
    if (s[0] == '+' || s[0] == '-') {
      s = s.substr(1);
    }
    if (s.size() == 0) {
      return false;
    } else {
      return true;
    }
  }

  bool isInteger(string s) {
    if (!parseAbsolute(s)) {
      return false;
    };
    return isPositiveInteger(s);
  }

  bool isPositiveInteger(string s) {
    for (auto item = s.begin(); item != s.end(); item++) {
      if (!IS_NUMBER(*item)) {
        return false;
      }
    }
    return true;    
  }

  bool isFloat(string s) {
    if (!parseAbsolute(s)) {
      return false;
    };
    int i = 0, len = s.size();
    for (; i < len; i++) {
      if (s[i] == '.') {
        break;
      }
    }
    if (i == len) {
      return isInteger(s);
    } else if (i == len - 1) {
      return isInteger(s.substr(0, len - 1));
    } else if (i == 0) {
      return isPositiveInteger(s.substr(i + 1));
    } else {
      return isInteger(s.substr(0, i)) && isPositiveInteger(s.substr(i + 1));
    }
  }
};