#include <algorithm>
#include <string>
#include <vector>

bool operator > (string &a, string &b) {
    int n = a.length();
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return true;
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> num_strs(n);
        for (int i = 0; i < n; ++i) {
            num_strs[i] = to_string(nums[i]);
        }

        sort(num_strs.begin(), num_strs.end(), [](string &a, string &b) { return a+b > b+a;});
        
        string result = "";
        for (auto str : num_strs) {
            result += str;
        }
        
        int x = result.find_first_not_of('0');
        if (x == string::npos) return "0";
        return result.substr(x);
    }
};
