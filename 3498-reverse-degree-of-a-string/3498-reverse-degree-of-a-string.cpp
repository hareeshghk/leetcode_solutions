class Solution {
public:
    int reverseDegree(string s) {
        // get degree 26-(c - 'a')

        // integer is enough because in worst case it will be 26 * (1+2+3...+1000) which fits into integer.
        int result = 0;
        for (int i = 0; i < s.length(); ++i) {
            result += (26-(s[i]-'a')) * (i+1);
        }

        return result;
    }
};