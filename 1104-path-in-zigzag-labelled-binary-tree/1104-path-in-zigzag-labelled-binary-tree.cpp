class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int val = 0;
        vector<int> ans;
        while (label/(1<<val) != 0) val++;
        
        // label belongs to val th row. which ranges from 2^(val-1) and 2^val -1
        if (val % 2 == 0) {
            label = (1<<(val-1)) + ((1<<val) - 1 - label);
        }
        
        int left, right;
        while(label != 0) {
            left = (1<<(val-1));
            right = ((1<<val)-1);
            
            if (val & 1) {
                ans.push_back(label);
            } else {
              ans.push_back(right -(label-left));
            }
            label = label/2;
            --val;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};