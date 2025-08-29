class Solution {
public:
    long long flowerGame(int n, int m) {
        // we need odd sum combinations
        // if x even then y odd
        // if x odd then y even.

        long long answer = n/2;
        answer = answer * (m/2);
        answer = 2 * answer;

        if (m % 2 != 0) {
            answer += n/2;
        }

        if (n%2 != 0) {
            answer += m/2;
        }

        return answer;
    }
};