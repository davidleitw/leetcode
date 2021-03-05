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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        unordered_map<int, ListNode*> hashMap;
        ListNode *curr = head;
        
        while(curr) {
            cnt++;
            hashMap[cnt] = curr;
            curr = curr->next;
        }
       
        if(cnt == n) {
            ListNode *del = head;
            head = head->next;
            delete del;
            return head;
        }
        hashMap[cnt-n]->next = hashMap[cnt-n+1]->next;
        delete hashMap[cnt-n+1];
        return head;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 11 MB, less than 37.46% of C++ online submissions for Remove Nth Node From End of List.