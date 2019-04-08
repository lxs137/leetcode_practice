class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        else if (nums.size() == 1)
            return true;
        int n = nums.size() - 1, reachStart = 0, reachEnd = 0;
        do {
            int range = reachEnd;
            for (int i = reachStart; i <= reachEnd; i++) {
                if (i + nums[i] > n) 
                    return true;
                if (i + nums[i] > reachEnd) {
                    reachStart = reachEnd + 1;
                }
                range = max(i + nums[i], range);
            }
            if (range == reachEnd)
                return false;
            else
                reachEnd = range;
        } while (reachStart < n && reachEnd < n);
        return true;
    }
};