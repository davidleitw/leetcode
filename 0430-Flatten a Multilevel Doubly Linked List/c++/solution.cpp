#include <bits/stdc++.h>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return nullptr;
        Node *solution = head;
        stack<Node*> s;
        while(head) {
            if(head->child) {
                if(head->next)
                    s.push(head->next);
                head->next = head->child;
                head->next->prev = head;
                head->child = nullptr;
            } 
            if(!head->next) break; 
            head = head->next;  
        }
        while(!s.empty()) {
            Node *tmp = s.top(); s.pop();
            head->next = tmp;
            tmp->prev = head;
            while(head->next) head = head->next;
        }
        return solution;
    }
};

// Runtime: 4 ms, faster than 97.71% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 7.6 MB, less than 15.33% of C++ online submissions for Flatten a Multilevel Doubly Linked List.