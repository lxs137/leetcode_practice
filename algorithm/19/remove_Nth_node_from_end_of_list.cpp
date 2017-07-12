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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(head == NULL || n == 0)
                return head;
            vector<ListNode*> ptr_arr;
            ListNode *cur = head;
            while(cur != NULL) {
                ptr_arr.push_back(cur);
                cur = cur->next;
            }
            int index = ptr_arr.size() - n;
            if(index == 0) {
                head = head->next;
            }
            else if(index == ptr_arr.size() - 1) {
                ptr_arr[index - 1]->next = NULL;
            }
            else {
                ptr_arr[index - 1]->next = ptr_arr[index]->next;
            }
            delete ptr_arr[index];
            return head;
        }
};
