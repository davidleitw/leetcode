#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int index = 0; 
        return decode(s, index);
    }
    string decode(string &s, int &index) {
        string solution = "";
        const int size = s.size();
        while(index < size && s[index] != ']') {
            if(!isNumber(s[index])) {
                solution += s[index];
                index++;
            } else {
                int cnt = 0;
                while(isNumber(s[index])) {
                    cnt = cnt * 10 + (s[index] - '0');
                    index++;
                }
                index++; // pass '['
                string temp = decode(s, index);
                index++; // pass ']'
                while(cnt) {
                    solution += temp;
                    cnt--;
                }
            }    
        }
        return solution;
    }
    bool isNumber(char c) {
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
// Memory Usage: 6.8 MB, less than 11.40% of C++ online submissions for Decode String.