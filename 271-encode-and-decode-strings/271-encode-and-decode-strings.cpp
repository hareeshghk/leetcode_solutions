#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string result = "";
        for (auto str : strs) {
            result += to_string(str.length()) + ".";
            result += str;
        }
        return result;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s.length() == 0) return vector<string>{""};
        vector<string> result;
        
        int idx = 0;
        while (idx < s.length()) {
            int numchars = 0;
            while (s[idx] != '.') {
                numchars = numchars*10 + (s[idx++]-'0');
            }
            
            result.push_back(s.substr(idx+1, numchars));
            idx = idx + 1 + numchars;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
