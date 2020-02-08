class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }
    int idxL = 0, idxR = 0, n = s.size();
    string minSubstr = "";
    map<char, int> chMapS, chMapT;
    for (auto it = t.begin(); it != t.end(); it++) {
      chMapS.emplace(*it, 0);
      auto item = chMapT.emplace(*it, 1);
      if (!item.second) {
        item.first->second += 1;
      }
    }
    do {
      while (idxR < n) {
        auto item = chMapS.find(s[idxR++]);
        if (item == chMapS.end()) {
          continue;
        }
        item->second += 1;
        if (chMapCover(chMapS, chMapT)) {
          cout << "expand (" << idxL << ", " << idxR << ")" << endl;
          if (minSubstr.empty() || idxR - idxL < minSubstr.size()) {
            minSubstr = s.substr(idxL, idxR - idxL);
            cout << "window = " << minSubstr << endl;
          }
          break;
        }
      }
      for (const auto &pair : chMapS) {
        cout << "  count(" << pair.first << ") = " << pair.second << endl;
      }

      while (idxL < idxR) {
        auto item = chMapS.find(s[idxL++]);
        if (item != chMapS.end()) {
          item->second -= 1;
        }
        if (chMapCover(chMapS, chMapT)) {
          if (minSubstr.empty() || idxR - idxL < minSubstr.size()) {
            minSubstr = s.substr(idxL, idxR - idxL);
            cout << "window = " << minSubstr << endl;
          }
        } else {
          break;
        }
      }
      cout << "extract (" << idxL << ", " << idxR << ")" << endl << endl;
    } while (idxR <= n && idxL < idxR);
    return minSubstr;
  }

  bool chMapCover(const map<char, int> &c1, const map<char, int> &c2) {
    if (c1.size() != c2.size()) {
      return false;
    }
    for (const auto &pair : c1) {
      auto it2 = c2.find(pair.first);
      if (it2 == c2.end() || it2->second > pair.second) {
        return false;
      }
    }
    return true;
  }
};
