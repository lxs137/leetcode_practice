class Solution {
    public:
        int maxArea(vector<int>& height) {
            int max_area = 0, min_height, i = 0, j = height.size() - 1;
            while(i < j) {
                min_height = min(height[i], height[j]);
                max_area = max(max_area, (j - i) * min_height);
                while(height[i] <= min_height && i < j)
                    i++;
                while(height[j] <= min_height && i < j)
                    j--;
            }
            return max_area;
        }
};
