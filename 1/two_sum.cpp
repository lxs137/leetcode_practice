class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> minus_map;
        std::vector<int> result;
        for(int i = 0, n = nums.size(); i < n; i++) {
            auto search = minus_map.find(nums[i]);
            if(search != minus_map.end()) {
                result.push_back(search->second);
                result.push_back(i);
                return result;
            }
            minus_map[target - nums[i]] = i;
        }
    }
};