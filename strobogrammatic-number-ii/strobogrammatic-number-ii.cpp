#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<string> result;
    unordered_map<char,char> valid_conversions;
    vector<string> findStrobogrammatic(int n) {
        valid_conversions['0'] ='0';
        valid_conversions['1'] ='1';
        valid_conversions['6'] ='9';
        valid_conversions['8'] ='8';
        valid_conversions['9'] ='6';
        
        backtrack("", 0, n);
        return result;
    }
    
    void backtrack(string curstring, int cur_length, int target_length) {
        if (cur_length == (target_length+1)/2) {
            
            if (target_length != 1 && curstring[0] == '0') return;
            
            if (target_length &1) {
                if (curstring[cur_length-1] == '6' || curstring[cur_length-1] == '9') return;
            }
            
            int start = cur_length-1;
            if (target_length &1) {
                start = cur_length-2;
            }
            for (; start >=0; --start) {
                curstring += valid_conversions[curstring[start]];
            }
            result.push_back(curstring);
            return;
        }
        
        for (auto val_pair : valid_conversions) {
            backtrack(curstring+val_pair.first, cur_length+1, target_length);
        }
    }
};
