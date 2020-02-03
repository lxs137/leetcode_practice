class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) {
      return 0;
    } else if (x == 1) {
      return 1;
    }
    int t = x / 2, preT = 1;
    do {
      preT = t;
      t = (t + x / t) / 2;
     } while (preT != t && t < preT);
    return t >= preT ? preT : t;
  }
};
