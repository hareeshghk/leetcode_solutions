#include <algorithm>
#include <vector>
using namespace std;

class node {
public:
    bool is_end;
    vector<node*> children;
    node() {
        children.resize(2, nullptr);
        is_end = false;
    }
};

class trie {
public:
    node* root;
    trie() {
        root = new node;
    }
    void insert(vector<int> bits) {
        auto current = root;
        for (int i = 0; i < bits.size(); i++) {
            if (current->children[bits[i]] == nullptr) {
                current->children[bits[i]] = new node;
            }
            current = current->children[bits[i]];
        }
        current->is_end = true;
    }
    
    int findmaxxor(vector<int> bits) {
        auto current = root;
        int result = 0;
        for (int i = 0; i < bits.size(); i++) {
            result = result << 1;
            if ((bits[i] == 0 && current->children[1] != nullptr) ||
               (bits[i] == 1 && current->children[0] != nullptr)) {
                result = result | 1;
                if (bits[i] == 0) current = current->children[1];
                else current = current->children[0];
            } else {
                if (current->children[0] != nullptr) current = current->children[0];
                else current = current->children[1];
            }
        }
        return result;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        auto head = new trie;
        head->insert(converttobits(nums[0]));
        int result = 0;
        for (int i = 1; i < n; ++i) {
            auto bits = converttobits(nums[i]);
            result = max(result, head->findmaxxor(bits));
            head->insert(bits);
        }
        return result;
    }
    
    vector<int> converttobits(int x) {
        vector<int> result(32, 0);
        int idx = 31;
        while (x!=0) {
            result[idx] = x%2;
            x/=2;
            idx--;
        }
        return result;
    }
};
