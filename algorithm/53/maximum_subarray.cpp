class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        vector<int> subArr = { nums[0] };
        int tempSum, tempMaxSum, maxSum = nums[0], maxRemainCount;
        for (int i = 1, n = nums.size(); i < n; i++) {
            subArr.push_back(nums[i]);
            tempSum = tempMaxSum = nums[i], maxRemainCount = 1;
            for (int k = 1, m = subArr.size(); k < m; k++) {
                tempSum += subArr[m - k - 1];
                if (tempSum > tempMaxSum) {
                    maxRemainCount = k + 1;
                    tempMaxSum = tempSum;
                }
            }
            maxSum = max(maxSum, tempMaxSum);
            subArr.erase(subArr.begin(), subArr.begin() + (subArr.size() - maxRemainCount));
            cout << tempMaxSum << ": ";
            for (int num : subArr) {
                cout << num << ",";
            }
            cout << endl;
        }
        return maxSum;
    }
};