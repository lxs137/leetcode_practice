typedef pair<int, int> Coord;

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    int height = board.size(), width = board[0].size();
    return findCoord(board, width, height, word).size() > 0;
  }

  vector<vector<Coord>> findCoord(vector<vector<char>>& board, int width, int height, string word) {
    vector<vector<Coord>> res;
    if (word.size() == 0) {
      return res;
    } else if (word.size() == 1) {
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
          if (board[i][j] == word[0]) {
            vector<Coord> solution;
            solution.emplace_back(i, j);
            res.emplace_back(solution);
          }
        }
      }
      return res;
    } else {
      auto part = findCoord(board, width, height, word.substr(0, word.size() - 1));
      if (part.size() == 0) {
        return res;
      }
      for (auto &line : part) {
        Coord tail = line.back();
        vector<Coord> solutionFiltered, solution({
          make_pair(tail.first - 1, tail.second),
          make_pair(tail.first + 1, tail.second),
          make_pair(tail.first, tail.second - 1),
          make_pair(tail.first, tail.second + 1)});
        for (auto &solItem : solution) {
          if (solItem.first < height && solItem.second < width
              && board[solItem.first][solItem.second] == word.back()) {
            solutionFiltered.emplace_back(solItem);
          }
        }
        solution.clear();
        // check whether coord exist
        for (auto &solItem : solutionFiltered) {
          int i = 0, n = line.size();
          while (i < n && line[i] != solItem) {
            i++;
          }
          if (i >= n) {
            solution.emplace_back(solItem);
          }
        }

        for (auto &solItem : solution) {
          vector<Coord> newLine(line);
          newLine.emplace_back(solItem);
          res.emplace_back(newLine);
        }
      }
      return res;
    }
  }
};
