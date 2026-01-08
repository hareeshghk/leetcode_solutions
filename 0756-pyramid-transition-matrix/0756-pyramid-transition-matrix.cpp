class Trie {
    vector<Trie*> children;
    bool isEnd;
public:
    Trie() {
        isEnd = false;
        children = vector<Trie*>(6, nullptr);
    }

    void insert(string str) {
        auto root = this;

        for (int i = 0; i < str.size(); ++i) {
            if (root->children[str[i]-'A'] == nullptr) {
                root->children[str[i]-'A'] = new Trie();
            }
            root = root->children[str[i]-'A'];
        }
        root->isEnd = true;
    }

    bool hasPrefix(string str) {
        auto root = this;

        for (int i = 0; i < str.size(); ++i) {
            if (root->children[str[i]-'A'] == nullptr) {
                return false;
            }
            root = root->children[str[i]-'A'];
        }
        return true;
    }
};

class Solution {
    unordered_map<string, vector<string>> allowedMap;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto str : allowed) {
            allowedMap[str.substr(0, 2)].push_back(str.substr(2));
        }

        return solve(bottom);
    }
private:
    bool solve(string base) {
        if (base.length() == 1) return true;

        return IterateString(base, 0, "");
    }

    bool IterateString(string base, int index, string current) {
        if (index == base.length()-1) {
            return solve(current);
        }

        bool result = false;
        for (auto str : allowedMap[base.substr(index, 2)]) {
            result = result || IterateString(base, index+1, current+str);
        }
        return result;
    }
};