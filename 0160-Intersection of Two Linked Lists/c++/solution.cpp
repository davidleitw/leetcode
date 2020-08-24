#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 記得要複習
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        ListNode *A = headA;
        ListNode *B = headB;
        while(A != B) {
            A = A ? A->next : headB;
            B = B ? B->next : headA;
        }
        return A;
    }
};

// Runtime: 28 ms, faster than 100.00% of C++ online submissions for Intersection of Two Linked Lists.
// Memory Usage: 14.7 MB, less than 54.76% of C++ online submissions for Intersection of Two Linked Lists.