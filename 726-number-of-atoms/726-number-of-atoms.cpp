#include <algorithm>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int idx;
    string countOfAtoms(string s) {
        unordered_map<string, int> freq;
        stack<int> st;
        int curval=1, stval=1;
        int idx = s.length()-1;
        
        while(idx >=0) {
            if(s[idx] == ')') {
                st.push(curval);
                stval = stval*curval;
                curval = 1;
                idx--;
            } else if(s[idx] =='(') {
                curval = 1;
                stval /= st.top();
                st.pop();
                idx--;
            } else if (isdigit(s[idx])) {
                int val = 0;
                int j = idx;
                while (isdigit(s[idx])) {
                    val += (s[idx]-'0') * pow(10, j-idx);
                    idx--;
                }
                // cout << "count: " << val << endl;
                curval = val;
            } else {
                string atom = "";

                while (idx >= 0 && isalpha(s[idx]) && !isupper(s[idx])) {
                    atom += s[idx];
                    idx--;
                }
                
                atom += s[idx];
                idx--;
                
                reverse(atom.begin(), atom.end());
                // cout << "atom name: " <<atom << endl;
                freq[atom] += curval * stval;
                curval = 1;
            }
        }
        
        vector<pair<string, int>> chars;
        
        for (auto val : freq) {
            chars.push_back(val);
        }
        
        sort(chars.begin(), chars.end(), [](pair<string,int>&a,pair<string,int>&b){return a.first < b.first;});
        
        string ans = "";
        
        for (auto val : chars) {
            ans += val.first;
            if (val.second != 1) ans += to_string(val.second);
        }
        return ans;
    }
    
};
