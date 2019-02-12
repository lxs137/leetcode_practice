class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        else if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        int split_idx = find_split(nums, 0, nums.size() - 1);
        int res = binary_search(nums, 0, split_idx, target);
        if (res != -1)
            return res;
        else 
            return binary_search(nums, split_idx + 1, nums.size() - 1, target);
    }
    int find_split(vector<int>& nums, int i, int j) {
        if (j == i || j - i == 1) {
            return i;
        }
        int center_idx = (i + j) / 2,
            l_center_idx = (i + center_idx) / 2,
            r_center_idx = (center_idx + j) / 2,
            center = nums[center_idx], 
            l_center = nums[l_center_idx],
            r_center = nums[r_center_idx];
        if (l_center <= center && center <= r_center) {
            if (nums[j] >= r_center) {
                return find_split(nums, i, l_center_idx);
            } else {
                return find_split(nums, r_center_idx, j);
            }
        } else if (l_center <= center && center >= r_center) {
            return find_split(nums, center_idx, r_center_idx);
        } else {
            return find_split(nums, l_center_idx, center_idx);
        }
    }
    int binary_search(vector<int>& nums, int i, int j, int target) {
        int center_idx = (i + j) / 2; 
        while (i <= j) {
            if (nums[center_idx] == target) {
                return center_idx;
            } else if (nums[center_idx] < target) {
                i = center_idx + 1;
            } else {
                j = center_idx - 1;
            }
            center_idx = (i + j) / 2;
        }
        return -1;
    }
};