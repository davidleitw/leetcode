#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        bool flag = false;
        set<ListNode*> s;
        
        while(head) {
            if(s.count(head) > 0) {
                flag = true;
                break;
            }
            
            s.insert(head);
            head = head->next;
        }
        return flag;
    }
};

// solution2, use fasert and slower pointer to compare. 
class Solution {
public:
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;
        ListNode *faster = head->next;
        
        while(faster && faster->next) {
            faster = faster->next->next;
            head = head->next;
            
            if(head == faster) // same node 
                return true;
        }
        
        return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Linked List Cycle.
// Memory Usage: 7.8 MB, less than 47.07% of C++ online submissions for Linked List Cycle.