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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int count = 0;
        unordered_map<int, ListNode*> hashMap;
        ListNode *curr = head;
        
        while(curr) {
            count++; 
            hashMap[count] = curr;
            curr = curr->next;
        }
    
        k %= count;
        if(k == 0) return head;
        
        ListNode *tail = hashMap[count - k];
        ListNode *newHead = tail->next;
        hashMap[count]->next = head;
        tail->next = nullptr;
        return newHead;
    }
    
};


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate List.
// Memory Usage: 12.1 MB, less than 29.99% of C++ online submissions for Rotate List.