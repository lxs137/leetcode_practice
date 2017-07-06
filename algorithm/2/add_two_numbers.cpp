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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL, *tail = NULL;
        int carry = 0, add;
        while(l1 || l2) {
            add = (l1 != NULL ? l1->val : 0) + 
                (l2 != NULL ? l2->val : 0) + carry;
            if(add >= 10) {
                carry = 1;
                append(&result, &tail, add - 10);
            }
            else {
                carry = 0;
                append(&result, &tail, add);
            }
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 != NULL)
                l2 = l2->next;
        }
        if(carry == 1)
            append(&result, &tail, 1);
        return result;
    }
    void append(ListNode **list, ListNode **tail, int i) {
        if(*list == NULL)
            *tail = *list = new ListNode(i);
        else {
            (*tail)->next = new ListNode(i);
            (*tail) = (*tail)->next;
        }
    }
};