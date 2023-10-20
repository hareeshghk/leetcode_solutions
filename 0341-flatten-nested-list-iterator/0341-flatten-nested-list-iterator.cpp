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
private:
    stack<vector<NestedInteger>::iterator> cStack, endStack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cStack.push(nestedList.begin());
        endStack.push(nestedList.end());
    }
    
    int next() {
        while (!cStack.empty()) {
            vector<NestedInteger>::iterator currentTop = cStack.top();
            if (currentTop == endStack.top()) {
                cStack.pop();
                endStack.pop();
                if (!cStack.empty()) {
                    auto curTop = cStack.top();
                    cStack.pop();
                    cStack.push(curTop+1);
                }
            } else {
                if (currentTop->isInteger()) {
                    cStack.pop();
                    cStack.push(currentTop+1);
                    cout << currentTop->getInteger() << endl;
                    return currentTop->getInteger();
                }
                
                cStack.push(currentTop->getList().begin());
                endStack.push(currentTop->getList().end());
            }
        }
        return -1;
    }
    
    bool hasNext() {
        while (!cStack.empty()) {
            vector<NestedInteger>::iterator currentTop = cStack.top();
            if (currentTop == endStack.top()) {
                cStack.pop();
                endStack.pop();
                if (!cStack.empty()) {
                    auto curTop = cStack.top();
                    cStack.pop();
                    cStack.push(curTop+1);
                }
            } else {
                if (currentTop->isInteger()) return true;
                
                cStack.push(currentTop->getList().begin());
                endStack.push(currentTop->getList().end());
            }
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */