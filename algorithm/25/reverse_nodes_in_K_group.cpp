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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(head == NULL || head->next == NULL || k == 1)
                return head;
            int width = 0;
            ListNode *cur = head, *next, *pre =NULL, *node = head;
            while(node) {
                width++;
                if(width % k == 0) {
                    head = node;
                    break;
                }
                node = node->next;
            }
            if(!node)
                return head;
            next = head;
            while(next) {
                if(width % k == 0) {
                    swap(pre, cur, next);
                    pre = cur;
                    next = cur = cur->next;
                }
                else {
                    next = next->next;
                    if(!next)
                        break;
                }
                width++;
            }
            return head;

        }
        void swap(ListNode *pre, ListNode *cur, ListNode *next) {
            ListNode *temp, *head = cur;
            while(cur != next) {
                temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            if(head->next != NULL)
                head->next->next = cur;
            head->next = cur->next;
            cur->next = pre;
        }
};
