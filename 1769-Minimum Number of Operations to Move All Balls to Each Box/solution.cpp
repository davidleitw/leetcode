static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int boxesNumber = boxes.size();
        if(boxesNumber == 0 || boxesNumber == 1) return vector<int>{0}; 
        
        int iterator;
        vector<int> solution(boxesNumber);
        for(int index = 0; index < boxesNumber; index++) {
            iterator = index+1;
            while(iterator < boxesNumber && boxes[iterator] != '1') {
                iterator++;
            }
            if(iterator == boxesNumber) break;
            for(int i = iterator; i >= 0; i--) {
                solution[i] += iterator - i;
            }
            index = iterator-1;
        }
        
        for(int index = boxesNumber - 1; index >= 0; index--) {
            iterator = index-1;
            while(iterator >= 0 && boxes[iterator] != '1') {
                iterator--;
            }
            if(iterator == -1) break;
            for(int i = iterator; i < boxesNumber; i++) {
                solution[i] += i - iterator;
            }
            index = iterator+1;
        } 
        
        return solution;
    }
};