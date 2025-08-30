#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char> mirror {{'0','0'}, {'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        
        int n = num.length();
        
        int left = 0, right = n-1;
        
        while (left <= right) {
            if (mirror.find(num[left]) == mirror.end() || mirror.find(num[right]) == mirror.end()) {
                return false;
            }
            
            if (mirror[num[left]] != num[right]) return false;
            
            ++left;
            --right;
        }
        
        return true;
    }
};
