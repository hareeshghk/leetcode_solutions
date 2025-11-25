class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        while (n!=1) {
            int x = n;
            int val = 0;

            while (x!=0) {
                val += ((x%10) * (x%10));

                x /= 10;
            }

            if (seen.find(val) != seen.end()) return false;
            
            seen.insert(val);
            n = val;
        }

        return true;
    }
};