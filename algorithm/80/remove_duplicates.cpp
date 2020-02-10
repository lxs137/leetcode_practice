class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }
    int idx = 1, i = 1, count = 1, preNum = nums[0];
    for (int n = nums.size(); i < n; i++) {
      nums[idx] = nums[i];
      if (nums[i] != preNum) {
        preNum = nums[i];
        count = 1;
        idx++;
      } else {
        if (count <= 1) {
          idx++;
        }
        count++;
      }
    }
    return idx;
  }
};
