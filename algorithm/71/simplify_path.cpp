class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> dirs;
    int i = 0, j = 0, n = path.size();
    bool inDir = false;
    while (i < n) {
      if (path[i] == '/') {
        if (i - j >= 2) {
          addDir(dirs, path.substr(j + 1, i - j - 1));
        }
        j = i;
      }
      i++;
    }

    if (i - j >= 2) {
      addDir(dirs, path.substr(j + 1, i - j - 1));
    }

    string res("");
    for (auto item = dirs.begin(); item != dirs.end(); item++) {
      res += ("/" + *item);
    }
    return res.empty() ? "/" : res;
  }

  void addDir(vector<string> &dirs, const string &dir) {
    if (dir.compare("..") == 0) {
      if (!dirs.empty()) {
        dirs.pop_back();        
      }
    } else if (dir.compare(".") != 0) {
      dirs.push_back(dir);
    }
  }
};
