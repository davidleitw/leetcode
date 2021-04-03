// MaxHeap solution, very dirty code QQ 

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> maxHeap;
        maxHeap.push(a);
        maxHeap.push(b);
        maxHeap.push(c);
        
        int n1;
        int n2;
        int cnt = 0;
        while(maxHeap.size() > 1) {
            n1 = maxHeap.top();
            maxHeap.pop();
            n2 = maxHeap.top();
            maxHeap.pop();
            if(n1 > 1) maxHeap.push(n1 - 1);
            if(n2 > 1) maxHeap.push(n2 - 1);
            cnt++;
        }
        return cnt;
    }
};

// Math solution!

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int sum = a + b + c;
        return min((sum / 2), (sum - max({a, b, c})));
    }
};