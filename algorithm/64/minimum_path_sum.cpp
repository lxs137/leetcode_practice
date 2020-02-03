class Solution {
 public:
  int *solution;
  int w = 0, h = 0;

  int minPathSum(vector<vector<int>>& grid) {
    h = grid.size();
    if (h == 0) {
      return 0;
    }
    w = grid[0].size();
    if (w == 0) {
      return 0;
    }
    solution = new int[w * h]();
    int res = minPath(grid, w - 1, h - 1);
    delete[] solution;
    return res;
  }

  int minPath(vector<vector<int>>& grid, int x, int y) {
    int res = solution[y * w + x];
    if (res != 0) {
      return res;
    }

    if (x == 0 && y == 0) {
      res = grid[0][0];
    } else if (x == 0) {
      for (int j = 0; j <= y; j++) {
        res += grid[j][0];
      }
    } else if (y == 0) {
      for (int i = 0; i <= x; i++) {
        res += grid[0][i];
      }
    } else {
      res = min(minPath(grid, x - 1, y), minPath(grid, x, y - 1)) + grid[y][x];
    }

    solution[y * w + x] = res;
    return res;
  }
};
