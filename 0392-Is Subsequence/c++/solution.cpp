#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int subIndex = 0;
        char targetPtr = s[subIndex];
        string target = "";
        
        for(char iter: t) {
            if(iter == targetPtr) {
                target += iter;
                targetPtr = s[++subIndex];
            }
        }
        
        if(target == s) 
            return true;
        return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.3 MB, less than 86.44% of C++ online submissions for Is Subsequence.