class Solution {
private:
    string inputString = "";
public:
    int myAtoi(string s) {
        inputString = s;
        // leading spaces removes
        removeSpaces();
        cout << inputString << endl;
        // identify the sign
        bool isPositive = isPositiveNumber();
        cout << inputString << " " << isPositive << endl;
        // get number if its crossing limits then keep them in limits

        return getNumber(isPositive);
    }
private:
    // remove leading spaces
    void removeSpaces() {
        int n = inputString.length();

        int start = 0;

        while (start < n && inputString[start] == ' '){
            ++start;
        }

        if (start == n) {
            inputString = "";
            return;
        }

        inputString = inputString.substr(start);        
    }

    // identify sign
    bool isPositiveNumber() {
        int n = inputString.length();

        if (n==0) return true;

        if (inputString[0] == '-') {
            inputString = inputString.substr(1);
            return false;
        }

        if (inputString[0] == '+') {
            inputString = inputString.substr(1);
            return true;
        }

        return true;
    }

    // get number
    int getNumber(bool isPositive) {
        int limit = INT_MAX;

        long long answer = 0;

        for (int i = 0; i < inputString.length(); ++i) {
            if (inputString[i]-'0' < 0 || inputString[i]-'0' > 9) break;

            answer = (answer * 10) + (inputString[i]-'0');

            if (isPositive && answer > limit) {
                return limit;
            } else if (!isPositive && answer-1 > limit) {
                return INT_MIN;
            }
        }

        if (!isPositive) {
            return -1 * answer;
        }

        return answer;
    }
};