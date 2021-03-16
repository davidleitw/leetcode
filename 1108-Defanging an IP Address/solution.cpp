class Solution {
public:
    string defangIPaddr(string address) {
        string ip = "";
        for(char n: address) {
            if(n == '.') ip += "[.]";
            else ip += n;
        }
        return ip;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defanging an IP Address.
// Memory Usage: 5.9 MB, less than 61.88% of C++ online submissions for Defanging an IP Address.