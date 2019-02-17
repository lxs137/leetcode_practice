class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return permute(nums);
    }
    vector<vector<int>> permute(const vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        } else if (nums.size() == 1) {
            vector<int> line({nums[0]});
            res.emplace_back(line);
            return res;
        } else if (nums.size() == 2) {
            vector<int> line1({nums[0], nums[1]});
            res.emplace_back(line1);
            if (nums[0] != nums[1]) {
                vector<int> line2({nums[1], nums[0]});               
                res.emplace_back(line2);
            }
            return res;
        } else {
            int curNum = nums[0];
            for (auto it = nums.begin(); it != nums.end(); it++) {
                if (it != nums.begin() && curNum == *it) {
                    cout << "pass: " << curNum << endl;
                    continue;
                } else {
                    curNum = *it;
                }
                vector<int> subNums(nums.begin(), it);
                subNums.insert(subNums.end(), it + 1, nums.end());
                auto subPermute = permute(subNums);
                for (auto &line : subPermute) {
                    line.push_back(*it);
                    res.emplace_back(line);
                }
            }
            return res;
        }
    }
};