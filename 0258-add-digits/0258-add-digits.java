class Solution {
    public int addDigits(int num) {
        while(num/10 != 0) {
            int answer = 0;
            while (num != 0) {
                answer += num%10;
                num /= 10;
            }
            num = answer;
        }
        return num;
    }
}