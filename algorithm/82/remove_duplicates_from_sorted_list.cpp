class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode *ptr = head->next, *temp = nullptr;
    int preVal = head->val;
    bool duplicate = false;
    vector<int> nums;

    while (ptr) {
      if (ptr->val != preVal) {
        if (!duplicate) {
          nums.push_back(preVal);
        }
        duplicate = false;
        preVal = ptr->val;
      } else {
        duplicate = true;
      }
      ptr = ptr->next;
    }

    if (!duplicate) {
      nums.push_back(preVal);
    }

    ptr = nullptr;
    for (auto it = nums.rbegin(); it != nums.rend(); it++) {
      temp = ptr;
      ptr = new ListNode(*it);
      ptr->next = temp;
    }

    return ptr;
  }
};