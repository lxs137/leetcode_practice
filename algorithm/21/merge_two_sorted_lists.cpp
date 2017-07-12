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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;
            ListNode *l0, *head;
            if(l1-> val < l2->val) {
                l0 = head = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                l0 = head = new ListNode(l2->val);
                l2 = l2->next;
            }
            while(l1 != NULL && l2 != NULL) {
                if(l1->val < l2->val) {
                    append(&l0, l1->val);
                    l1 = l1->next;
                }
                else {
                    append(&l0, l2->val);
                    l2 = l2->next;
                }
            }
            if(l1 == NULL) {
                while(l2 != NULL) {
                    append(&l0, l2->val);
                    l2 = l2->next;
                }
            }
            if(l2 == NULL) {
                while(l1 != NULL) {
                    append(&l0, l1->val);
                    l1 = l1->next;
                }
            }
            return head;
        }
        void append(ListNode **res, int val) {
            if(res == NULL) {
                *res = new ListNode(val);
            }
            else {
                (*res)->next = new ListNode(val);
                (*res) = (*res)->next;
            } 
        }
};
