class Solution {
    unordered_map<int, vector<int>> allowedMap;
    unordered_set<int> seen;
    vector<vector<int>> store;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto str : allowed) {
            allowedMap[getEncoded(str[0], str[1])].push_back(str[2] - 'A');
        }

        vector<int> bottomVec = vector<int>(bottom.length());

        for (int i = 0; i < bottomVec.size(); ++i) {
            bottomVec[i] = bottom[i]-'A';
        }

        store = vector<vector<int>>(bottomVec.size(), vector<int>(bottomVec.size()));

        return solve(bottomVec, bottomVec.size());
    }
private:
    inline int getEncoded(char a, char b) {
        return ((a-'A')<<3) + (b-'A');
    }

    inline int getEncoded(int a, int b) {
        return (a<<3) + b;
    }

    // each number is maximum 3 bits so moving each number by 3 bits.
    int convert(vector<int> &base, int sz) {
        int val = 0;

        for (int i = 0; i < sz; ++i) {
            val = (val<<3) + (base[i]+1);
        }
        return val;
    }

    bool solve(vector<int> &base, int sz) {
        if (sz == 1) return true;

        int converted = convert(base, sz);
        if (seen.find(converted) != seen.end()) return false;

        if(IterateString(base, 0, store[sz-1], sz)) return true;

        seen.insert(converted);
        return false;
    };

    bool IterateString(vector<int> &base, int index, vector<int> &current, int sz) {
        if (index == sz-1) {
            return solve(current, sz-1);
        }

        for (auto nextVal : allowedMap[getEncoded(base[index], base[index+1])]) {
            current[index] = nextVal;
            if(IterateString(base, index+1, current, sz)) return true;
        }
        return false;
    }
};