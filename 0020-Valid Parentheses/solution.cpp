#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        
        stack<char> S;
        for(char c: s) {
            if(c == '(' || c == '{' || c == '[') {
                S.push(c);
            } else {
                if(S.empty()) return false;
                switch(c) {
                    case ')':
                        if(S.top() != '(') {
                            return false;
                        }
                        break;
                    case '}':
                        if(S.top() != '{') {
                            return false;
                        }
                        break;
                    case ']':
                        if(S.top() != '[') {
                            return false;
                        }
                        break;
                }
                S.pop();
            }
        }
        return S.empty();
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.3 MB, less than 25.83% of C++ online submissions for Valid Parentheses.