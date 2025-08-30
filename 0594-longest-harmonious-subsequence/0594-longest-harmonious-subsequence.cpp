#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> counter;

        for (auto num : nums){
            counter[num]++;
        }

        int answer = 0;
        for (auto [key, value] : counter) {
            if (counter.find(key-1) != counter.end()) {
                answer = max(answer, counter[key] + counter[key-1]);
            }
        }
        return answer;
    }
};
