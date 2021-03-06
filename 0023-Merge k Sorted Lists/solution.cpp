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
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty() || (lists.size() == 1 && !lists[0])) return nullptr;
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        
        for(ListNode *head: lists) {
            if(head) {
                minHeap.push(head);
            }
        }
        
        while(!minHeap.empty()) {
            ListNode *node = minHeap.top();
            if(node->next) {
                minHeap.push(node->next);
            }
            curr->next = node;
            curr = curr->next;
            minHeap.pop();
        }
        curr->next = nullptr;
        return head->next;
    }
};

// Runtime: 12 ms, faster than 99.85% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 13.3 MB, less than 67.56% of C++ online submissions for Merge k Sorted Lists.
