#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> boxes;
    int removeBoxes(vector<int>& boxes) {
        this->boxes = boxes;
        int n = boxes.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n+1, -1)));
        return calculateboxes(0, boxes.size()-1, 0);
    }
    
    vector<vector<vector<int>>> dp;
    int calculateboxes(int left, int right, int k) {
        if (left > right) return 0;
        
        while (right > left && boxes[right] == boxes[right-1]) {
            right--;
            k++;
        }
        
        if (dp[left][right][k] != -1) return dp[left][right][k];
        
        int val = calculateboxes(left, right-1, 0) + (k+1)*(k+1);
        
        for (int i = left; i < right; i++) {
            if (boxes[i] == boxes[right]) {
                val = max(val, calculateboxes(left, i, k+1) + calculateboxes(i+1, right-1, 0));
            }
        }
        return dp[left][right][k] = val;
    }
};
