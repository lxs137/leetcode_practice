class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m < n) {
      int temp = m;
      m = n;
      n = temp;
    }
    long res = 1;
    for (int max = m + n - 1; m < max; m++) {
      res *= m;
    }
    return res / factorial(n - 1);
  }
  long factorial(int n) {
    long res = 1;
    for (int i = 1; i <= n; i++) {
      res *= i;
    }
    return res;
  }
};
