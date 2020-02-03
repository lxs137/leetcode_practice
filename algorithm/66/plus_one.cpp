class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> res(digits);
    int flag = 1;
    for (auto item = res.rbegin(); item != res.rend(); item++) {
      if (flag == 0) {
        break;
      }
      if (*item + flag == 10) {
        flag = 1;
        *item = 0;
      } else {
        (*item) += 1;
        flag = 0;
      }
    }
    if (flag == 1) {
      res.insert(res.begin(), 1);
    }
    return res;
  }
};
