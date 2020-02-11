class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return false;
    } else if (nums.size() == 1) {
      return nums[0] == target;
    }
    int i = 0, j = nums.size() - 1, middle;
    while (i <= j) {
      // cout << "nums(" << i << ") = " << nums[(i + j) / 2] << "\t";
      // cout << "nums(" << j << ") = " << nums[(i + j) / 2] << "\t";
      // cout << "nums(" << ((i + j) / 2) << ") = " << nums[(i + j) / 2] << endl;
      middle = (i + j) / 2;
      if (middle == i || middle == j) {
        return nums[i] == target || nums[j] == target;
      }
      if (nums[middle] == target) {
        return true;
      }
      if (nums[middle] == nums[j]) {
        if (nums[middle] == nums[i]) {
          vector<int> left(nums.begin() + i, nums.begin() + middle), right(nums.begin() + middle, nums.begin() + j);
          return search(left, target) || search(right, target);
        } else if (nums[middle] < nums[i]) {
          if (binarySearch(nums, middle + 1, j, target)) {
            return true;
          }
          j = middle - 1;
        } else {
          if (binarySearch(nums, i, middle - 1, target)) {
            return true;
          }
          i = middle + 1;
        }
      } else if (nums[middle] > nums[j]) {
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
    int middle;
    while (i <= j) {
      middle = (i + j) / 2;
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