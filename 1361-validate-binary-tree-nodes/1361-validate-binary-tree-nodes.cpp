class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inboundCount = vector<int>(n, 0);
        vector<int> outboundCount = vector<int>(n, 0);
        int numEdges = 0;
        
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                inboundCount[leftChild[i]]++;
                outboundCount[i]++;
                numEdges++;
            }
            
            if (rightChild[i] != -1) {
                inboundCount[rightChild[i]]++;
                outboundCount[i]++;
                numEdges++;
            }
        }
        
        if (numEdges != n-1) return false;
        
        int zeroInboundNodes = 0;
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (inboundCount[i] > 1 || outboundCount[i] > 2) {
                return false;
            }
            
            if (inboundCount[i] == 0) {
                zeroInboundNodes++;
                root = i;
            }
        }
        
        if (zeroInboundNodes != 1) return false;
        int visited = 0;
        dfs(root, leftChild, rightChild, visited);
        if (visited == n) return true;
        return false;
    }
    
    void dfs(int index, vector<int> &left, vector<int> &right, int &count) {
        count++;
        if (left[index] != -1) {
            dfs(left[index], left, right, count);
        }
        
        if (right[index] != -1) {
            dfs(right[index], left, right, count);
        }
    }
};