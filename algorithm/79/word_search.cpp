typedef pair<int, int> Coord;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int height = board.size(), width = board[0].size();
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (board[i][j] == word.front()) {
          vector<Coord> footprint({make_pair(i, j)});
          if (findCoord(board, width, height, word.substr(1), footprint)) {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool findCoord(vector<vector<char>>& board, int width, int height, string word, vector<Coord> &footprint) {
    // cout << word << ": " << endl;
    // for (Coord &item : footprint) {
    //   cout << "(" << item.first << ", " << item.second << ") -> ";
    // }
    // cout << endl;
    if (word.size() == 0) {
      return true;
    }
    Coord tail = footprint.back();
    vector<Coord> solution({
      make_pair(tail.first - 1, tail.second),
      make_pair(tail.first, tail.second + 1),
      make_pair(tail.first + 1, tail.second),
      make_pair(tail.first, tail.second - 1)});
    for (Coord &item : solution) {
      if (item.first < height && item.second < width
        && item.first >= 0 && item.second >= 0
        && board[item.first][item.second] == word.front()) {
        int i = footprint.size() - 2;
        while (i >= 0 && footprint[i] != item) {
          i--;
        }
        if (i < 0) {
          footprint.emplace_back(item.first, item.second);
          if (findCoord(board, width, height, word.substr(1), footprint)) {
            return true;
          }
          footprint.pop_back();
        }
      }
    }
    return false;
  }
};