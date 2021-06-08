class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode *idx = head, *ptr = head->next;
    int preVal = head->val;
    while (ptr) {
      if (ptr->val != preVal) {
        idx = idx->next;
        idx->val = ptr->val;
        preVal = ptr->val;
      }
      ptr = ptr->next;
    }

    ptr = head;
    while (ptr) {
      if (ptr->next == idx->next) {
        ptr->next = nullptr;
        break;
      }
      ptr = ptr->next;
    }
    return head;
  }
};
