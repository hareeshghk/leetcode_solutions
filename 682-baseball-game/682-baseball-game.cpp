#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int size = 0;
        vector<int> result;
        for (auto op : ops) {
            if (op == "+") {
                result.push_back(result[size-1]+result[size-2]);
                ++size;
            } else if (op == "D") {
                result.push_back(result[size-1]*2);
                ++size;
            } else if (op == "C") {
                result.pop_back();
                --size;
            } else {
                result.push_back(stoi(op));
                ++size;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < size; ++i) {
            ans += result[i];
        }
        return ans;
    }
};
