class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size(); ++i) {
            maxHeap.push(nums[i]);
            if(maxHeap.size() > k) maxHeap.pop();
        }
    }
    
    int add(int val) {
        maxHeap.push(val);
        if(maxHeap.size() > K) maxHeap.pop();
        return maxHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */