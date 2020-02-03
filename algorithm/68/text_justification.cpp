class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int curWidth = 0;
    vector<string> res;
    vector<string> line;
    for (auto item = words.begin(); item != words.end(); item++) {
      if (curWidth == 0) {
        line.push_back(*item);
        curWidth = item->size();
      } else if (curWidth + item->size() + 1 <= maxWidth) {
        line.push_back(*item);
        curWidth += (item->size() + 1);
      } else {
        // concat string
        res.push_back(concatWords(line, maxWidth));
        line.clear();
        line.push_back(*item);
        curWidth = item->size();
      }
    }
    if (!line.empty()) {
      string s("");
      for (auto item = line.begin(); item != line.end(); item++) {
        maxWidth -= (item->size() + 1);
        s += *item;
        s += " ";
      }
      if (maxWidth > 0) {
        s += string(maxWidth, ' ');        
      } else if (maxWidth < 0) {
        s = s.substr(0, s.size() + maxWidth);
      }
      res.push_back(s);
    }
    return res;
  }

  string concatWords(const vector<string> &words, int lineWidth) {
    int freeSpace = lineWidth;
    for (auto item = words.begin(); item != words.end(); item++) {
      freeSpace -= item->size();
    }
    int slot = (words.size() <= 1 ? 1 : (words.size() - 1) );
    vector<int> spaces(slot, 0);
    while (freeSpace > 0) {
      for (int i = 0; i < slot && freeSpace > 0; i++) {
        spaces[i]++;
        freeSpace--;
      }
    }
    string res("");
    for (int i = 0; i < slot; i++) {
      res += words[i];
      res += string(spaces[i], ' ');
    }
    if (words.size() == 1) {
      return res;
    } else {
      return res + words[slot];
    }
  }
};
