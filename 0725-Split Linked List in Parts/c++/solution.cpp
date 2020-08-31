#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// version 1, very bad solution. 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(!root) {
            vector<ListNode*> solution(k, nullptr);
            return solution;
        }
        vector<ListNode*> v;
        while(root) {
            v.push_back(root);
            root = root->next;
        }
        int length = v.size();
        vector<ListNode*> solution;
        if(length < k) {
            for(int i = 0; i < length; ++i) {
                v[i]->next = nullptr;
                solution.push_back(v[i]);
            }
            for(int i = length; i < k; ++i)
                solution.push_back(nullptr);
            return solution;
        } 
        
        int l = length/k; // 12 / 4 = 3, 25 / 4 = 6;
        if(length%k == 0) {
            for(int i = 0; i < length; i += l) {
                v[i+l-1]->next = nullptr;
                solution.push_back(v[i]);
            }
            return solution;
        }
        
        int left = k;
        int range = 0;
        int index = 0;
        int now_length = length;
        while(solution.size() != k) {
            if(now_length%left != 0) {
                range = (length/k) + 1;
                v[index+range-1]->next = nullptr;
                solution.push_back(v[index]);
            } else {
                range = length/k;
                v[index+range-1]->next = nullptr;
                solution.push_back(v[index]);
            }
            index = index+range;
            left--;
            now_length = now_length-range;
        }   
        return solution;
    }
};

// Runtime: 8 ms, faster than 82.42% of C++ online submissions for Split Linked List in Parts.
// Memory Usage: 8.5 MB, less than 33.07% of C++ online submissions for Split Linked List in Parts.

// version2, a litter butter solution. 
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        if(!root) {
            vector<ListNode*> solution(k, nullptr);
            return solution;
        }
        vector<ListNode*> v;
        while(root) {
            v.push_back(root);
            root = root->next;
        }
        int length = v.size();
        vector<ListNode*> solution;
        if(length < k) {
            for(int i = 0; i < length; ++i) {
                v[i]->next = nullptr;
                solution.push_back(v[i]);
            }
            for(int i = length; i < k; ++i)
                solution.push_back(nullptr);
            return solution;
        } 
        
        int index = 0;
        int exnum = length%k; // 7%3 = 1;
        int range = length/k; // 7/3 = 2;
        for(int turn = 0; turn < exnum; ++turn) {
            solution.push_back(v[index]);
            v[index+range]->next = nullptr;
            index = index+range+1;
        }
        range--;
        for(int turn = exnum; turn < k; ++turn) {
            solution.push_back(v[index]);
            v[index+range]->next = nullptr;
            index = index+range+1;
        }
        return solution;
    }
};

// Runtime: 4 ms, faster than 98.60% of C++ online submissions for Split Linked List in Parts.
// Memory Usage: 8.5 MB, less than 17.48% of C++ online submissions for Split Linked List in Parts.