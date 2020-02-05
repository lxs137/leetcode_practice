class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    }
    int cur = 2, pre = 1, temp;
    for (int i = 3; i <= n; i++) {
      temp = cur;
      cur = cur + pre;
      pre = temp;
    }
    return cur;  
  }
};
