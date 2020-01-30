class Solution {
 public:
  string getPermutation(int n, int k) {
    if (n == 1) {
      return "1";
    }
    string res = "";
    vector<char> numbers{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i = n - 1, f = factorial(n - 1);
    do {
      cout << k << ", " << f << endl;
      int count = (k - 1) / f;
      res += numbers[count];
      numbers.erase(numbers.begin() + count);
      k -= f * count;
      f /= i;
      i--;
    } while (i >= 1);
    res += numbers.front();
    return res;
  }

  int factorial(int n) {
    int res = 1;
    while (n >= 1) {
      res *= n;
      n--;
    }
    return res;
  }
};
