class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int> sumCounter;
        int maxCount = 0;
        int answer = 1;
        int digitSum, currentCount;
        for (int i = 1; i <= n; ++i) {
            digitSum = getDigitSum(i);
            sumCounter[digitSum]++;
            currentCount = sumCounter[digitSum];
            if (maxCount < currentCount) {
                maxCount = currentCount;
                answer = 1;
            } else if (maxCount == currentCount) {
                answer++;
            }
        }
        return answer;
    }
private:
    int getDigitSum(int x) {
        int ans = 0;
        while (x != 0) {
            ans += x%10;
            x /= 10;
        }
        return ans;
    }
};