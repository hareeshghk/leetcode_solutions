class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for (int i = left; i <= right; ++i) {
            if (sd(i)) ans.push_back(i);
        }
        return ans;
    }
private:
    bool sd(int x) {
        int k = x;

        while (k != 0) {
            int l = k%10;
            if (l == 0 || x%l != 0) return false;
            k/=10;
        }
        return true;
    }
};