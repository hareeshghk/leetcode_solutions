#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int expectedNumber = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] > expectedNumber) {
                expectedNumber++;
            }
        }
        
        return expectedNumber;
    }
};
