class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minPosNum = 0, numSize = nums.size();
        for(int num : nums) {
            if (num >= 1 && (minPosNum == 0 || num < minPosNum))
                minPosNum = num;
        }
        if (minPosNum == 0 || minPosNum > 1)
            return 1;
        for(int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] < 1 || nums[i] > numSize) {
                nums[i] = 0;
                continue;
            } else if (nums[i] - 1 == i) {
                continue;
            }
            int coverVal = nums[nums[i] - 1], tempVal;
            nums[nums[i] - 1] = nums[i];
            nums[i] = 0;
            while(coverVal >= 1 && coverVal <= numSize && coverVal != nums[coverVal - 1]) {
                tempVal = nums[coverVal - 1];
                if (tempVal == coverVal)
                    break;
                nums[coverVal - 1] = coverVal;
                coverVal = tempVal;
            }
        }
        for(auto it = nums.begin(); it != nums.end(); it++) {
            if (*it == 0)
                return *(it - 1) + 1;
        }
        return nums.back() + 1;
    }
};