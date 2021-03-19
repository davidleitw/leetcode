

class Solution {
public:

    int candy(vector<int>& ratings) {
        const int nums = ratings.size();
        if(nums == 0) return 0;
        
        vector<int> childrens(nums, 1);
        
        for(int i = 1; i < nums; ++i) {
            if(ratings[i] > ratings[i-1]) {
                childrens[i] = childrens[i-1] + 1;
            }
        }
        
        for(int i = nums-1; i > 0; i--) {
            if(ratings[i-1] > ratings[i]) {
                childrens[i-1] = max(childrens[i-1], childrens[i]+1);
            }
        }
        int cnt = 0;
        for(int i = 0; i < nums; ++i) cnt += childrens[i];
        return cnt;
    }
};