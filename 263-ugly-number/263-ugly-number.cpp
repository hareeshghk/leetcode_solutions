class Solution {
public:
    bool isUgly(int n) {
        vector<int> vals{30,15,10,6,5,3,2};
        
        for (auto val : vals) {
            while (n!=0 && n%val == 0) {
                n /= val;
            }
        }
        
        return (n==1);
    }
};