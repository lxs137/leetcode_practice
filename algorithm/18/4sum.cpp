class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> res;
            if(nums.size() <= 3)
                return res;
            map<int, pair<int, int>> nums_pair;
            sort(nums.begin(), nums.end());
            nums_pair[nums[0]] = make_pair(0, 0);
            int last_key = nums[0];
            for(int i = 1, n = nums.size(); i < n; i++) {
                if(nums[i] == last_key)
                    nums_pair[nums[i]].second = i;
                else {
                    nums_pair[nums[i]] = make_pair(i, i);
                    last_key = nums[i];
                }
            }
            for(int i = 0, n = nums.size(); i < n; i++) {
                if(nums[i] > target && nums[i] > 0)
                    break;
                for(int j = i + 1; j < n; j++) {
                    if(nums[i] + nums[j] > target && nums[j] > 0)
                        break;
                    for(int k = j + 1; k < n; k++) {
                        if(nums[i] + nums[j] + nums[k] > target && nums[k] > 0)
                            break;
                        auto search = nums_pair.find(target - nums[i] - nums[j] - nums[k]);
                        if(search != nums_pair.end() && search->second.second > k)
                            res.emplace_back(vector<int>({nums[i], nums[j], nums[k], search->first}));
                        k = nums_pair[nums[k]].second;
                    }
                    j = nums_pair[nums[j]].second;
                }
                i = nums_pair[nums[i]].second;
            }
            return res;
        }
};
