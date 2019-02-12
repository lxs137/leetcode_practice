class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0)
            return res;
        else if (candidates.size() == 1) {
            if (candidates[0] == target) {
                res.emplace_back(candidates);
                return res;
            }
        }
        sort(candidates.begin(), candidates.end());
        trySolve(candidates, target, res, candidates[0]);
        vector<multiset<int>> solves;
        vector<vector<int>> uniqueRes;
        for(auto &line : res) {
            multiset<int> temp(line.begin(), line.end());
            auto findRes = find(solves.begin(), solves.end(), temp);
            if (findRes == solves.end()) {
                uniqueRes.emplace_back(line.begin(), line.end());
                solves.push_back(temp);
            }
        }
        return uniqueRes;
    }
    void trySolve(vector<int> &candidates, int target, vector<vector<int>> &res, int lastChoose) {
        if (target == 0) {
            vector<int> temp({});
            res.emplace_back(temp);
            return;
        } else if (candidates[0] > target) {
            return;
        } else if (candidates[0] == target) {
            vector<int> temp({target});
            res.emplace_back(temp);
            return;
        }
        for(auto chooseCandidate : candidates) {
            if (chooseCandidate >= lastChoose && chooseCandidate <= target) {
                vector<vector<int>> tempRes;
                trySolve(candidates, target - chooseCandidate, tempRes, chooseCandidate);
                for(auto &line : tempRes) {
                    line.push_back(chooseCandidate);
                    res.emplace_back(line);
                }
            }
        }
    }
};