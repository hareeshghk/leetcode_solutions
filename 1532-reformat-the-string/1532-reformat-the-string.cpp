#include <cmath>
#include <string>

class Solution {
public:
    string reformat(string s) {
        int n = s.length();
        int numChars = 0;
        for (auto ch : s) {
            if (ch-'a' >=0 && ch-'a' < 26) numChars++;
        }
        int numDigits = n-numChars;

        if (abs(numDigits-numChars) > 1) return "";
        string answer = s;
        int digitIndex, charIndex;
        if (numChars >= numDigits) {
            digitIndex = 1;
            charIndex = 0;
        } else {
            digitIndex = 0;
            charIndex = 1;
        }

        for (auto ch : s) {
            if (ch-'a' >= 0 && ch-'a' < 26) {
                answer[charIndex] = ch;
                charIndex += 2;
            } else {
                answer[digitIndex] = ch;
                digitIndex += 2;
            }
        }
        return answer;
    }
};
