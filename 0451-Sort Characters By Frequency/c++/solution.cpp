class Solution {
public:
    struct cmp {
        bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
            return p1.second < p2.second;
        }
    };
    string frequencySort(string s) {
        unordered_map<char, int> hashMap;
        for(char c: s) hashMap[c]++;
        
        string solution = "";
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> maxHeap(hashMap.begin(), hashMap.end());
        while(!maxHeap.empty()) {
            pair<char, int> p = maxHeap.top();
            maxHeap.pop();
            solution += string(p.second, p.first);
        }
        return solution;
    }
};

// reference: https://stackoverflow.com/questions/4485203/c-stl-using-map-with-priority-queue