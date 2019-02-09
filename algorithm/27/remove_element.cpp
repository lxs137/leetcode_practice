class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if(size == 0)
            return size;
        else if(size == 1) {
            if(nums[0] == val)
                return 0;
            else
                return 1;
        }
        int i = 0;
        for(int j = 0; j < size; j++) {
            if(nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};