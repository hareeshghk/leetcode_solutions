class Solution {
public:
    string intToRoman(int num) {
        int pos = 0;
        string ans;

        unordered_map<int, unordered_map<int, string>> mp;
        mp[0] = unordered_map<int, string>{{1, "I"}, {2,"II"}, {3, "III"},{4 ,"IV"},{5,"V"}, {6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"}};
        mp[1] = unordered_map<int, string>{{1,"X"}, {2,"XX"}, {3,"XXX"},{4 ,"XL"},{5,"L"}, {6,"LX"},{7,"LXX"},{8,"LXXX"},{9,"XC"}};
        mp[2] = unordered_map<int, string>{{1, "C"}, {2,"CC"}, {3,"CCC"},{4,"CD"},{5,"D"}, {6,"DC"},{7,"DCC"},{8,"DCCC"},{9,"CM"}};
        mp[3] = unordered_map<int, string>{{1,"M"}, {2,"MM"}, {3,"MMM"}};
        while (num != 0) {
            int val = num % 10;
            string cur = mp[pos][val];
            ans = cur + ans;
            num /= 10;
            ++pos;
        }
        return ans;
    }
    
};