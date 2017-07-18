/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == NULL || head->next == NULL) 
                return head;
            bool sign = true;
            ListNode *cur = head, *next = head->next, *pre = NULL;
            head = next;
            while(next) {
                if(sign) {
                    swap(pre, cur, next);
                    pre = next;
                    next = cur->next;
                }
                else {
                    pre = cur;
                    cur = next;
                    next = next->next;                
                }
                sign = !sign;
            }
            return head;
        }
        void swap(ListNode *pre, ListNode *cur, ListNode *next) {
            if(pre != NULL) {
                pre->next = next;
            }
            cur->next = next->next;
            next->next = cur;
        }
};
