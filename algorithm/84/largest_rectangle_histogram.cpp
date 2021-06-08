class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    return rectHeightAndArea(heights.begin(), heights.end() - 1).second;
  }

  // pair<height, area>
  pair<int, int> rectHeightAndArea(vector<int>::iterator left, vector<int>::iterator right) {
    int heightL = *left, heightR = *right;
    if (left == right) {
      return make_pair(heightL, heightL);
    } else if (right == left + 1) {
      int height = min(heightL, heightR), area = 2 * height;
      if (area > heightL && area > heightR) {
        return make_pair(height, area);
      } else if (heightL > heightR) {
        return make_pair(heightL, heightL);
      } else {
        return make_pair(heightR, heightR);
      }
    } else {
      pair<int, int> preSol = rectHeightAndArea(left + 1, right - 1);
      int preSolHeight = preSol.first, preSolArea = preSol.second, width = right - left + 1,
        heightL = min(preSolHeight, heightL), areaL = heightL * (width + 1),
        heightR = min(preSolHeight, heightR), areaR = heightR * (width + 1),
        heightAll = min({preSolHeight, heightL, heightR}), areaAll = heightAll * (width + 2);
      vector<pair<int, int>> solutions({
        preSol,
        make_pair(heightL, areaL),
        make_pair(heightR, areaR),
        make_pair(heightAll, areaAll)
      });
      return *max_element(solutions.begin(), solutions.end(),
        [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; });
    }
  }
};
