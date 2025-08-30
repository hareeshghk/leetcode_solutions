#include <vector>

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size()-1;
        int possible_answer = -1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if (letters[mid] <= target) {
                left = mid+1;
            } else {
                possible_answer = mid;
                right = mid-1;
            }
        }
        
        if (possible_answer == -1) return letters[0];
        return letters[possible_answer];
    }
};
