#include <unordered_set>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> square_numbers;
        
        int val = 0;
        long long int squared_val = 0;
        
        while (squared_val <= c) {
            square_numbers.insert(squared_val);
            squared_val += 2*val + 1;
            ++val;
        }
        
        for (auto num: square_numbers) {
            if (square_numbers.count(c-num) != 0) return true;
        }
        return false;
    }
};
