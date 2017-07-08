class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> res;
            if(nums.size() < 3)
                return res;
            sort(nums.begin(), nums.end());
            map<int, pair<int, int>> nums_pair;
            nums_pair[nums[0]]  = make_pair(0, 0);
            int last_key = nums[0];
            for(int i = 1, n = nums.size(); i < n; i++) {
                if(nums[i] != last_key) {
                    last_key = nums[i];
                    nums_pair[nums[i]] = make_pair(i, i);
                }
                else
                    nums_pair[nums[i]].second = i;
            }
            int  target;
            for(int i = 0, n = nums.size(); i < n; i++) {
                target = -nums[i];
                for(int j = i + 1; j < n; j++) {
                    auto search = nums_pair.find(target - nums[j]);
                    if(search != nums_pair.end() && search->second.second > j) {
                        res.push_back(vector<int>({nums[i], nums[j], search->first}));
                        j = nums_pair[nums[j]].second;
                    }
                }
                i = nums_pair[nums[i]].second;
            }
            return res;
        }
};
