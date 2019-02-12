class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res({-1, -1});
        if (nums.size() == 0) {
            return res;
        } else if (nums.size() == 1) {
            if (nums[0] == target) {
                res[0] = res[1] = 0;
            }
            return res;
        }
        int search_idx = binary_search(nums, 0, nums.size() - 1, target);
        if (search_idx == -1)
            return res;
        int i = search_idx, j = search_idx, max_idx = nums.size() - 1;
        while (i >= 0 && nums[i] == target) {
            i--;
        } 
        while (j <= max_idx && nums[j] == target) {
            j++;
        }
        res[0] = i < 0  ? 0 : (nums[i] == target ? i : i + 1);
        res[1] = j > max_idx ? max_idx : (nums[j] == target ? j : j - 1);
        return res;
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