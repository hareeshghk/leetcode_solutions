class Solution {
    unordered_map<int, vector<int>> allowedMap;
    unordered_set<int> seen;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto str : allowed) {
            allowedMap[getEncoded(str[0], str[1])].push_back(str[2] - 'A');
        }

        vector<int> bottomVec = vector<int>(bottom.length());

        for (int i = 0; i < bottomVec.size(); ++i) {
            bottomVec[i] = bottom[i]-'A';
        }

        return solve(bottomVec);
    }
private:
    inline int getEncoded(char a, char b) {
        return ((a-'A')<<3) + (b-'A');
    }

    inline int getEncoded(int a, int b) {
        return (a<<3) + b;
    }

    // each number is maximum 3 bits so moving each number by 3 bits.
    int convert(vector<int> &base) {
        int val = 0;

        for (auto x : base) {
            val = (val<<3) + (x+1);
        }
        return val;
    }

    bool solve(vector<int> &base) {
        if (base.size() == 1) return true;
        int converted = convert(base);
        if (seen.find(converted) != seen.end()) return false;

        vector<int> current = vector<int>(base.size()-1);

        if(IterateString(base, 0, current)) return true;

        seen.insert(converted);
        return false;
    };

    bool IterateString(vector<int> &base, int index, vector<int> &current) {
        if (index == base.size()-1) {
            return solve(current);
        }

        for (auto nextVal : allowedMap[getEncoded(base[index], base[index+1])]) {
            current[index] = nextVal;
            if(IterateString(base, index+1, current)) return true;
        }
        return false;
    }
};