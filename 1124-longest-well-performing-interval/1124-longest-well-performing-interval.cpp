#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> seen;
        int count = 0;
        
        int ans = 0;
        for (int day = 0; day < n; ++day) {
            count += (hours[day]>8?1:-1);
            if(count > 0) {
                ans = day + 1;
            } else {
                if (seen.find(count-1) != seen.end()) {
                    ans = max(ans, day - seen[count-1]);
                }
                if (seen.find(count) == seen.end()) seen[count] = day;
            }
        }
        
        return ans;
    }
};
