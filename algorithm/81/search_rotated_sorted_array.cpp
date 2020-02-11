class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1, middle;
    while (i <= j) {
      middle = (i + j) / 2;
      if (nums[middle] == target) {
        return true;
      }
      if (nums[middle] > nums[j]) {
        if (binarySearch(nums, i, middle - 1, target)) {
          return true;
        }
        i = middle + 1;
      } else {
        if (binarySearch(nums, middle + 1, j, target)) {
          return true;
        }
        j = middle - 1;
      }
    }
    return false;
  }

  bool binarySearch(const vector<int>& nums, int i, int j, int target) {
    int middle = (i + j) / 2;
    while (i <= j) {
      if (nums[middle] == target) {
        return true;
      } else if (nums[middle] > target) {
        j = middle - 1;
      } else {
        i = middle + 1;
      }
    }
    return false;
  }
};
