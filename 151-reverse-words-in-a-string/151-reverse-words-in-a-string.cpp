class Solution {
public:
    string reverseWords(string s) {
        auto result = reverseWords(s, ' ');
        
        if (result.length() == 0) return result;
        
        result.erase(result.size()-1);
        return result;
    }
    
    string reverseWords(string &s, char delim) {
        string result = "";
        
        int start=0, end = 0;
        
        for (start = s.find_first_not_of(delim, end); start != string::npos;) {
            end = s.find(delim, start);
            result = s.substr(start, end-start) + " " + result;
            start = s.find_first_not_of(delim, end);
        }
        return result;
    }
};