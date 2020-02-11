class Solution {
 public:
  void sortColors(vector<int>& nums) {
    if (nums.empty()) {
      return;
    }
    int idxZero = 0, idxTwo = nums.size() - 1, idxCur = 0, n = nums.size();
    while (idxCur <= idxTwo) {
      if (nums[idxCur] == 0) {
        nums[idxCur] = nums[idxZero];
        nums[idxZero] = 0;
        idxZero++;
        idxCur++;
      } else if (nums[idxCur] == 2) {
        nums[idxCur] = nums[idxTwo];
        nums[idxTwo] = 2;
        idxTwo--;
      } else {
        idxCur++;
      }
    }
  }
};