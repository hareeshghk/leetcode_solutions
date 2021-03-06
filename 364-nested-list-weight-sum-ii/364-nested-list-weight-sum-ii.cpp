/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int maxdepth, totalSum, productWithDepthSum;
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // initialization
        maxdepth = 1;
        totalSum = 0;
        productWithDepthSum = 0;
        
        RecurseSolve(nestedList, 1);
        return (((maxdepth+1)*totalSum) - productWithDepthSum);
    }
    
    void RecurseSolve(vector<NestedInteger>& nestedList, int depth) {
        maxdepth = max(maxdepth, depth);
        for (auto obj : nestedList) {
            if (obj.isInteger()) {
                totalSum += obj.getInteger();
                productWithDepthSum += obj.getInteger()*depth;
            } else {
                RecurseSolve(obj.getList(), depth+1);
            }
        }
    }
};