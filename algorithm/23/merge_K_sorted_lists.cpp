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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            list<ListNode*> first;
            for(auto node : lists) {
                if(node != NULL)
                    first.push_back(node);
            }
            if(first.empty())
                return NULL;
            first.sort([](const ListNode *a, const ListNode *b){
                    return a->val < b->val;
                    });
            ListNode *head = new ListNode(0), *cur = head, *node;
            do {
                node = first.front();
                cur = append(cur, node->val);
                first.pop_front();
                node = node->next;
                if(node != NULL) {
                    if(first.empty())
                        first.push_back(node);
                    else {
                        for(auto it = first.begin(); it != first.end(); it++) {
                            if((*it)->val > node->val) {
                                first.insert(it, node);
                                break;
                            }
                        }
                        if(first.back()->val <= node->val)
                            first.push_back(node);  
                    }
                }
            } while(!first.empty());
            return head->next;
        }
        ListNode* append(ListNode *node, int val) {
            node->next = new ListNode(val);
            return node->next;
        }
}; 
