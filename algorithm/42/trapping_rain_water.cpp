class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        int maxH = 0, bottom = 0, water = 0;
        for(int h : height) {
            maxH = (h > maxH) ? h : maxH;
        }
        while(maxH > bottom) {
            water += trapUnit(height, bottom);
            bottom++;
        }
        return water;
    }
    int trapUnit(vector<int>& height, int bottom) {
        int water = 0, temp = 0;
        bool inTrap = false;
        for(int h : height) {
            if (h <= bottom) {
                if (inTrap)
                    temp++;
            } else if (inTrap) {
                water += temp;
                temp = 0;
            } else {
                inTrap = true;
            }
        }
        return water;
    } 
};