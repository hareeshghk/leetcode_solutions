class Solution {
    string suffix;
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        // given condititon taht suffix will have elements less than limit so no need to check.
        // Get number of elements with s as suffix till finish and start-1 then subtract them.
        suffix = s;
        long long fItems = getNumberOfValues(finish, limit, s);
        long long sItems = getNumberOfValues(start-1, limit, s);
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

    bool isInRange(int index, vector<int>& limit) {
        for (int i = index, x = 0; i < limit.size(); ++i) {
            if ((suffix[x]-'0') < limit[i]) return true;
            if ((suffix[x]-'0') > limit[i]) return false;
            x++;
        }
        return true;
    }

    long long getNumberOfItemsInRange(int index, vector<int>& limitArray, int limit,int targetStartIndex, bool prevLimit) {
        if (index == limitArray.size()) return 1LL;
        if (index == targetStartIndex) {
            if (!prevLimit) {
                return 1LL;
            } else {
                if (isInRange(index, limitArray)) {
                    return 1LL;
                } else {
                    return 0LL;
                }
            }
        }
        long long result = 0;

        if (prevLimit) {
            if (limitArray[index] <= limit) {
                result += limitArray[index] * getNumberOfItemsInRange(index+1, limitArray, limit, targetStartIndex, false);
                // equal to limitArrayCase
                result += getNumberOfItemsInRange(index+1, limitArray, limit, targetStartIndex, true);
            } else {
                result += (limit+1) * getNumberOfItemsInRange(index+1, limitArray, limit, targetStartIndex, false);
            }
        } else {
            result += (limit+1) * getNumberOfItemsInRange(index+1, limitArray, limit, targetStartIndex, false);
        }
        return result;
    }

    long long getNumberOfValues(long long maxlimit, int digitLimit, string suff) {
        int digits = getNumDigits(maxlimit);
        if (suff.length() > digits) return 0;

        int targetStartIndex = digits - suff.length();

        vector<int> maxLimitArray = vector<int>(digits);
        for (int i = digits-1; i >=0; --i) {
            maxLimitArray[i] = maxlimit%10;
            maxlimit/=10;
        }

        return getNumberOfItemsInRange(0, maxLimitArray, digitLimit, targetStartIndex, true);
    }
};