class Solution {
    unordered_map<char, vector<int>> mapping;
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer;

        mapping['2'] = {'a', 'b', 'c'};
        mapping['3'] = {'d', 'e', 'f'};
        mapping['4'] = {'g', 'h', 'i'};
        mapping['5'] = {'j', 'k', 'l'};
        mapping['6'] = {'m', 'n', 'o'};
        mapping['7'] = {'p', 'q', 'r', 's'};
        mapping['8'] = {'t', 'u', 'v'};
        mapping['9'] = {'w', 'x', 'y', 'z'};

        string current(digits.length(), 'a');
        
        traverse(digits, 0, current, answer);
        return answer;
    }
private:
    void traverse(string digits, int index, string &current, vector<string> &answer) {
        if (index == digits.length()) {
            answer.push_back(current);
            return;
        }

        for (auto ch : mapping[digits[index]]) {
            current[index] = ch;
            traverse(digits, index+1, current, answer);
        }
    }
};