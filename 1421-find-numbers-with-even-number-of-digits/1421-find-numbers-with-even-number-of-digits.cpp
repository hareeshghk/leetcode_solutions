class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for (auto num : nums) {
            if (getNumDigits(num) %2 == 0) ++answer;
        }        
        return answer;
    }
private:
    inline int getNumDigits(int x) {
        int result = 0;
        while (x != 0) {
            result++;
            x /= 10;
        }
        return result;
    }
};