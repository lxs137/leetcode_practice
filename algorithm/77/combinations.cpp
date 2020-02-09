class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    return combineRange(1, n, k);
  }

  vector<vector<int>> combineRange(int i, int j, int len) {
    vector<vector<int>> res;
    if (j - i + 1 < len) {
      return res;
    } else if (j - i + 1 == len) {
      vector<int> line;
      while (i <= j) {
        line.push_back(i);
        i++;
      }
      res.emplace_back(line);
      return res;
    }
    if (len == 1) {
      while (i <= j) {
        vector<int> line;
        line.push_back(i);
        res.emplace_back(line);
        i++;
      }
      return res;
    } else {
      len--;
      for (int k = j - len; k >= i; k--) {
        auto part = combineRange(k + 1, j, len);
        for (auto &line : part) {
          line.insert(line.begin(), k);
          res.emplace_back(line);
        }
      }
      return res;
    }
  }
};
