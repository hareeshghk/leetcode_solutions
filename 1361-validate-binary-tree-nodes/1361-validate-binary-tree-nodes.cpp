#include <algorithm>
#include <stack>
#include <unordered_set>
#include <vector>

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        
        if (root == -1) return false;
        
        auto seen = unordered_set<int>();
        auto st = stack<int>();
        st.push(root);
        seen.insert(root);
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            
            if (leftChild[top] != -1) {
                if (seen.find(leftChild[top]) != seen.end()) return false;
                st.push(leftChild[top]);
                seen.insert(leftChild[top]);
            }
            
            if (rightChild[top] != -1) {
                if (seen.find(rightChild[top]) != seen.end()) return false;
                st.push(rightChild[top]);
                seen.insert(rightChild[top]);
            }
        }
        return seen.size()==n;
    }
    
private:
    int findRoot(int n, const vector<int>& leftChild, const vector<int>& rightChild) {
        auto distinct = unordered_set<int>();
        
        for (int i = 0; i < n; ++i) {
            distinct.insert(leftChild[i]);
            distinct.insert(rightChild[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (distinct.find(i) == distinct.end()) return i;
        }
        
        return -1;
    }
};
