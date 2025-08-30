#include <cmath>
#include <vector>

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int modval = grid[0][0]%x;
        int s = grid.size() * grid[0].size();
        int neededIndex = s/2;
        vector<int> allNums = vector<int>(s);
        int iter = 0;
        for (auto& r : grid) {
            for (auto& c : r) {
                if (c%x != modval) return -1;
                allNums[iter++] = c;
            }
        }

        mysort(allNums, 0, s-1, neededIndex);
        int median = allNums[neededIndex];

        int numSteps = 0;
        for (auto& r : grid) {
            for (auto& c : r) {
                numSteps += (abs(c-median)/x);
            }
        }

        return numSteps;
    }
private:
    void mysort(vector<int> &vals, int start, int end, int index) {
        if (start >= end) return;

        int pivot = end;
        int wall = start;
        int temp;
        for (int i = start; i < end; ++i) {
            if (vals[i] < vals[pivot]) {
                temp = vals[i];
                vals[i] = vals[wall];
                vals[wall] = temp;
                wall++;
            }
        }

        temp = vals[wall];
        vals[wall] = vals[pivot];
        vals[pivot] = temp;

        if (index == wall) return;

        if (index < wall) {
            mysort(vals, start, wall-1, index);
        } else {
            mysort(vals, wall+1, end, index);
        }
    }
};
