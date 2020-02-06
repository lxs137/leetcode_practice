class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }
    int height = matrix.size(), width = matrix[0].size(), offsetI = 0, offsetJ = width * height - 1, middle, middleX, middleY;

    while (offsetI <= offsetJ) {
      middle = (offsetI + offsetJ) / 2;
      middleX = middle / width;
      middleY = middle - middleX * width;
      if (matrix[middleX][middleY] == target) {
        return true;
      } else if (matrix[middleX][middleY] < target) {
        offsetI = middle + 1;
      } else {
        offsetJ = middle - 1;
      }
    }
    return false;
  }
};
