class Solution {
  int *solution;
  int width;
 public:
  int minDistance(string word1, string word2) {
    int i = word1.size(), j = word2.size();
    width = j;
    vector<char> s1(word1.begin(), word1.end()), s2(word2.begin(), word2.end());
    solution = new int[i * j]();
    int res = disWithCache(s1, s2, i, j);
    delete[] solution;
    return res;
  }

  int disWithCache(vector<char> s1, vector<char> s2, int i, int j) {
    if (i == 0) {
      return j;
    }
    if (j == 0) {
      return i;
    }
    int offset = (i - 1) * width + j - 1, res = solution[offset];
    if (res != 0) {
      return res;
    }
    res = dis(s1, s2, i, j);
    solution[offset] = res;
    return res;
  }

  int dis(vector<char> s1, vector<char> s2, int i, int j) {
    if (s1[i - 1] == s2[j - 1]) {
      vector<char> _s1(s1.begin(), s1.end() - 1), _s2(s2.begin(), s2.end() - 1);
      return disWithCache(_s1, _s2, i - 1, j - 1);
    }

    int dis1, dis2, dis3;
    // add char at i
    {
      vector<char> _s1(s1), _s2(s2.begin(), s2.end() - 1);
      dis1 = disWithCache(_s1, _s2, i, j - 1);
    }
    // delete char at i
    {
      vector<char> _s1(s1.begin(), s1.end() - 1), _s2(s2);
      dis2 = disWithCache(_s1, _s2, i - 1, j);
    }
    // replace char at i
    {
      vector<char> _s1(s1.begin(), s1.end() - 1), _s2(s2.begin(), s2.end() - 1);
      dis3 = disWithCache(_s1, _s2, i - 1, j - 1);
    }
    return min(dis1, min(dis2, dis3)) + 1;
  }
};