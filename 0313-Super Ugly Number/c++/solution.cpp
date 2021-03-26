class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> minHeap;
        minHeap.push(1);
        
        long long int _min = 1;
        int count = 0;
        while(count < n) {
            _min = minHeap.top(); 
            minHeap.pop();
            while(!minHeap.empty() && minHeap.top() == _min) minHeap.pop();
            count++;
            
            for(int prime: primes) minHeap.push(_min * prime);
        }
        return _min;
    }
};