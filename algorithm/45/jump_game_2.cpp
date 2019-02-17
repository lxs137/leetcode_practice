class Solution {
 public:
    // startIdx, minJumpTimes
    map<int, int> reaches;
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int step = 0, n = nums.size() - 1, reachStart = 0, reachEnd = 0;
        do {
            step++;
            int range = reachEnd;
            for (int i = reachStart; i <= reachEnd; i++) {
                if (i + nums[i] > reachEnd) {
                    reachStart = reachEnd + 1;
                }
                range = max(i + nums[i], range);
            }
            reachEnd = range;
        } while (reachStart < n && reachEnd < n);
        return step;
    }
};
