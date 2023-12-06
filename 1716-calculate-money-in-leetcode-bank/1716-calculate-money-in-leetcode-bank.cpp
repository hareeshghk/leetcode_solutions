class Solution {
public:
    int totalMoney(int n) {
        int numweeks = n/7;
        int remainingdays = n%7;
        
        // sigma 1 to numweeks (28 + 7*(ithweek-1))
        // 28*numweeks + 7*(numweeks-1 * numweeks/2)
        // days *(numsweeks)+ ((days) * (days+1)/2)
        
        
        int answer = (28 * (numweeks)) + (7 * (((numweeks-1) * numweeks))/2);
        
        answer += (remainingdays * numweeks) + ((remainingdays * (remainingdays+1))/2);
        return answer;
    }
};