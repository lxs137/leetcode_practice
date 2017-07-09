class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            if(nums.size() <= 3) {
                int result = 0;
                for(int a: nums)
                    result += a;
                return result;            
            }
            sort(nums.begin(), nums.end());
            int sum_min, sum_max, target_close, n = nums.size();
            sum_min = nums[0] + nums[1] + nums[2];
            sum_max = nums[n - 1] + nums[n - 2] + nums[n - 3];
            target_close = (abs(sum_min - target) > abs(sum_max - target) ? sum_max : sum_min);
            for(int i = 0, j, k, sum; i < n; i++) {
                j = i + 1, k = n - 1;
                while(j < k) {
                    sum = nums[i] + nums[j] + nums[k];
                    if(sum == target)
                        return target;
                    target_close = (abs(target_close - target) > abs(sum - target) ? sum : target_close);
                    if(sum > target)
                        k--;
                    else
                        j++;
                }

            }
            return target_close;
        }
};
