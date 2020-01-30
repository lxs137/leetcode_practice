/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *ptr = head, *tail = head;
    int len = 1;
    while (tail->next != nullptr) {
      len++;
      tail = tail->next;
    }
    k = k % len;

    while (++k < len) {
      ptr = ptr->next;
    }

    tail->next = head;
    head = ptr->next;
    ptr->next = nullptr;
    return head;
  }

  int length(ListNode* head) {
    int len = 0;
    while (head != nullptr) {
      len++;
      head = head->next;
    }
    return len;
  }
};