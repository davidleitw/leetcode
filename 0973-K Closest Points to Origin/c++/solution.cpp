class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> minHeap(points.begin(), points.end());
        
        vector<vector<int>> solution;
        for(int i = 0; i < k; ++i) {
            solution.push_back(minHeap.top());
            minHeap.pop();
        }
        return solution;
    }
private: 
    // 自己定義排序方式
    struct cmp {
        bool operator()(vector<int> &p, vector<int> &q) {
            return (p[0] * p[0] + p[1] * p[1]) > (q[0] * q[0] + q[1] * q[1]);
        }
    };
};