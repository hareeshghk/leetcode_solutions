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

class IteratorPair {
private:
    vector<NestedInteger>::iterator currentIterator, endIterator;
public:
    IteratorPair(vector<NestedInteger> &nestedList) {
        currentIterator = nestedList.begin();
        endIterator = nestedList.end();
    }
    
    vector<NestedInteger>::iterator getCurrent() {
        return currentIterator;
    }
    
    vector<NestedInteger>::iterator getEnd() {
        return endIterator;
    }
    
    bool isCompleted() {
        return currentIterator == endIterator;
    }
    
    void increment() {
        currentIterator++;
    }
};

class NestedIterator {
private:
    stack<IteratorPair*> iteratorStack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        iteratorStack.push(new IteratorPair(nestedList));
    }
    
    int next() {
        while (!iteratorStack.empty()) {
            auto currentTop = iteratorStack.top();
            if (currentTop->isCompleted()) {
                iteratorStack.pop();
            } else {
                if (currentTop->getCurrent()->isInteger()) {
                    int value = currentTop->getCurrent()->getInteger();
                    currentTop->increment();
                    return value;
                }
                
                auto newPair = new IteratorPair(currentTop->getCurrent()->getList());
                currentTop->increment();
                iteratorStack.push(newPair);
            }
        }
        return -1;
    }
    
    bool hasNext() {
        while (!iteratorStack.empty()) {
            auto currentTop = iteratorStack.top();
            if (currentTop->isCompleted()) {
                iteratorStack.pop();
            } else {
                if (currentTop->getCurrent()->isInteger()) {
                    return true;
                }
                auto newPair = new IteratorPair(currentTop->getCurrent()->getList());
                currentTop->increment();
                iteratorStack.push(newPair);
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