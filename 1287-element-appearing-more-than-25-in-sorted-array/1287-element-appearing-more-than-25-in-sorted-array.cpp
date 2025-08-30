#include <vector>

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        
        int minFreqForAnswer = n/4;
        
        for (int i = 0; i < n-minFreqForAnswer; ++i) {
            if (arr[i] == arr[i+minFreqForAnswer]) return arr[i];
        }
        
        return -1;
    }
};
