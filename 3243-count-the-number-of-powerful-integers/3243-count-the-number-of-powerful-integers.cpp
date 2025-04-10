class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // given condititon taht suffix will have elements less than limit so no need to check.
        // Get number of elements with s as suffix till finish and start-1 then subtract them.

        long long fItems = getNumberOfValues(finish, limit, s);
        cout << fItems << endl;
        long long sItems = getNumberOfValues(start-1, limit, s);
        cout << sItems << endl;
        return fItems-sItems;
    }

private:
    int getNumDigits(long long x) {
        int digits = 0;
        while (x!=0) {
            x/=10;
            digits++;
        }
        return digits;
    }

    bool isInRange(int index, vector<int>& limit, vector<int>& target) {
        for (int i = index; i < limit.size(); ++i) {
            if (target[i] < limit[i]) return true;
            if (target[i] > limit[i]) return false;
        }
        return true;
    }

    long long getNumberOfItemsInRange(int index, vector<int>& limitArray, int limit,vector<int>& target, bool prevLimit) {
        if (index == limitArray.size()) return 1LL;
        if (target[index] != -1) {
            if (!prevLimit) {
                return 1LL;
            } else {
                if (isInRange(index, limitArray, target)) {
                    return 1LL;
                } else {
                    return 0LL;
                }
            }
        }
        long long result = 0;

        if (prevLimit) {
            if (limitArray[index] <= limit) {
                result += ((long long)limitArray[index]) * getNumberOfItemsInRange(index+1, limitArray, limit, target, false);
                // equal to limitArrayCase
                result += getNumberOfItemsInRange(index+1, limitArray, limit, target, true);
            } else {
                result += ((long long)(limit+1)) * getNumberOfItemsInRange(index+1, limitArray, limit, target, false);
            }
        } else {
            result += ((long long)(limit+1)) * getNumberOfItemsInRange(index+1, limitArray, limit, target, false);
        }
        return result;
    }

    long long getNumberOfValues(long long maxlimit, int digitLimit, string suffix) {
        int digits = getNumDigits(maxlimit);
        if (suffix.length() > digits) return 0;

        vector<int> target = vector<int>(digits, -1);
        for (int i = target.size()-1, j = suffix.length()-1; j>=0; --j) {
            target[i] = suffix[j]-'0';
            i--;
        }

        vector<int> maxLimitArray = vector<int>(digits);
        for (int i = digits-1; i >=0; --i) {
            maxLimitArray[i] = maxlimit%10;
            maxlimit/=10;
        }

        return getNumberOfItemsInRange(0, maxLimitArray, digitLimit, target, true);
    }
};