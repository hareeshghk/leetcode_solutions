class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; ++i) {
            s = getRLE(s);
        }
        return s;
    }
private:
    string getRLE(string str) {
        int n = str.length();
        string result = "";

        int start = 0;
        int length;
        while (start < n) {
            int j = start + 1;
            while (j < n && str[j] == str[start]) {
                j++;
            }

            length = j-start;
            result += to_string(length);
            result += str[start];
            start = j;
        }
        return result;
    }
};