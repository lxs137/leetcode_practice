class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return 0;
        else if (nums.size() == 1)
            return nums[0] >= target ? 0 : 1;
        int i = 0, j = nums.size() - 1, center_idx = (i + j) / 2; 
        while (i < j) {
            if (nums[center_idx] == target) {
                return center_idx;
            } else if (nums[center_idx] < target) {
                i = center_idx + 1;
            } else {
                j = center_idx - 1;
            }
            center_idx = (i + j) / 2;
        }
        return nums[i] >= target ? i: i + 1;
    }
};