class Solution {
 public:
  int *solution;
  int w = 0, h = 0;

  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    h = obstacleGrid.size();
    if (h == 0) {
      return 0;
    }
    w = obstacleGrid[0].size();
    if (w == 0) {
      return 0;
    }

    solution = new int[w * h]();
    return uniquePath(obstacleGrid, w - 1, h - 1);
  }

  int uniquePath(vector<vector<int>>& grid, int x, int y) {
    int res = solution[y * w + x];
    if (res != 0) {
      return res;
    }

    if (x == 0 && y == 0) {
      res = grid[0][0] ? 0 : 1;
    } else if (x == 0) {
      res = grid[y][x] ? 0 : uniquePath(grid, x, y - 1);
    } else if (y == 0) {
      res = grid[y][x] ? 0 : uniquePath(grid, x - 1, y);
    } else {
      if (grid[y][x]) {
        res = 0;
      } else {
        res = uniquePath(grid, x - 1, y) + uniquePath(grid, x, y - 1);
      }
    }

    solution[y * w + x] = res;
    return res;
  }
};
