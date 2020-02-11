class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode *idx = head, *ptr = head->next;
    int preVal = head->val;
    bool duplicate = false;
    while (ptr) {
      if (ptr->val != preVal) {
        if (duplicate) {
          idx->val = ptr->val;
          duplicate = false;
        }
        preVal = ptr->val;
        idx = idx->next;
      } else {
        duplicate = true;
      }
      ptr = ptr->next;
    }

    if (head == idx) {
      return nullptr;
    }
    ptr = head;
    while (ptr) {
      if (ptr->next == idx) {
        ptr->next = nullptr;
        break;
      }
      ptr = ptr->next;
    }
    return head;
  }
};
