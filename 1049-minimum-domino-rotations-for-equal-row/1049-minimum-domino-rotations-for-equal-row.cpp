#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        // get common number first.
        vector<int> commonValues = getCommon(tops[0], bottoms[0], tops[1], bottoms[1]);
        if (commonValues.size() == 0) return -1;
        // calculate common number on top and bottom.
        int minRotations = n+1;
        int currentRotations;
        for (auto commonValue : commonValues) {
            currentRotations = getRotations(tops, bottoms, commonValue);
            if (currentRotations!= -1) {
                minRotations = min(minRotations, currentRotations);
            }
        }

        if (minRotations == n+1) return -1;
        return minRotations;
    }
private:
    vector<int> getCommon(int t1, int b1, int t2, int b2) {
        vector<int> result;
        if (t1 == t2 || t1==b2) {
            result.push_back(t1);
        }

        if (b1 == t2 || b1==b2) {
            result.push_back(b1);
        }

        return result;
    }

    int getRotations(vector<int> &tops, vector<int> &bottoms, int commonValue) {
        int n = tops.size();
        int forTopRotations = 0, forBottomRotations = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != commonValue) {
                if (bottoms[i] == commonValue) {
                    forTopRotations++;
                } else {
                    return -1;
                }
            }

            if (bottoms[i] != commonValue) {
                if (tops[i] == commonValue) {
                    forBottomRotations++;
                } else {
                    return -1;
                }
            }
        }
        return min(forTopRotations, forBottomRotations);
    }
};
