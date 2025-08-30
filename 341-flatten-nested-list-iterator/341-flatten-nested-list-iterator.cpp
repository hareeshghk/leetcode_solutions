#include <iostream>
#include <list>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    // stack<pair<vector<NestedInteger>, int>> st;
    vector<int> store;
    int idx;
    int total_nums;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        idx = 0;
        Dfs(nestedList);
        // if (nestedList.size() != 0) st.push(pair<vector<NestedInteger>, int>(nestedList, 0));
        total_nums = store.size();
    }
    
    void Dfs(vector<NestedInteger> &nestedList) {
        for (auto n : nestedList) {
            if (n.isInteger()) {
                store.push_back(n.getInteger());
            } else {
                Dfs(n.getList());
            }
        }
    }
    
    int next() {
        return store[idx++];
//         auto cur = st.top();
//         st.pop();
        
//         while (true) {
//             int idx = cur.second;
//             if (cur.first[cur.second].isInteger()) {
//                 if (cur.second + 1 < cur.first.size()) {
//                     ++cur.second;
//                     st.push(cur);
//                 }
//                 return cur.first[idx].getInteger();
//             } else {
//                 if (cur.second + 1 < cur.first.size()) {
//                     ++cur.second;
//                     st.push(cur);
//                 }
//                 cur = pair<vector<NestedInteger>, int>(cur.first[idx].getList(), 0);
//             }
//         }
    }
    
    bool hasNext() {
        return idx < total_nums;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
