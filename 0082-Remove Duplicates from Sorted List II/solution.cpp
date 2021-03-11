/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur && cur->next) {
            ListNode *start = cur;
            while(start->next && start->val == start->next->val) {
                start = start->next;
            }
            
            if(cur == head && cur != start) {
                head = start->next;
                cur = head;
            } else if(cur == start) {
                pre = cur;
                cur = cur->next;
            } else {
                pre->next = start->next;
                cur = pre;
            }
        }
        return head;
    }
};