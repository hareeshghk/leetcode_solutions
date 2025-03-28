class DSU {
    vector<int> parents, size;
public:
    DSU(int n) {
        parents = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }

    bool unionfind(int a, int b) {
        int pa = findParent(a);
        int pb = findParent(b);

        if (pa == pb) {
            return false;
        }

        if (size[pa] >= size[pb]) {
            parents[pb] = pa;
            size[pa] += size[pb];
        } else {
            parents[pa] = pb;
            size[pb] += size[pa];
        }

        return true;
    }

    int getConnectedCount(int x) {
        int px = findParent(x);
        return size[px];
    }
private:
    int findParent(int x) {
        if (parents[x] != x) {
            parents[x] = findParent(parents[x]);
        }
        return parents[x];
    }
};

class Node {
    int row, col, value;
public:
    Node(int r, int c, int val) {
        row = r; col = c; value = val;
    }
    int getRow() {
        return row;
    }
    int getColumn() { return col;}
    int getValue() {return value;}
};

class Query {
    int index, value;
public:
    Query(int idx, int val) {
        index = idx;
        value = val;
    }

    int getIndex() {return index;}
    int getValue() {return value;}
};

class Solution {
public:
    // O(M*N + O(k*logK) + O(M*N log(M*N)))
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<Node> nodes;
        vector<Query> qs;
        int rows = grid.size();
        int cols = grid[0].size();
        int n = rows * cols;
        // O(M*N) time, O(M*N) space
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                nodes.push_back(Node(i, j, grid[i][j]));
            }
        }

        // O(K) time, O(K) Space
        for (int i = 0; i < queries.size(); ++i) {
            qs.push_back(Query(i, queries[i]));
        }


        // O(M*N log(M*N)) time, O(1) space
        sort(nodes.begin(), nodes.end(), [](Node &a, Node &b) {
            return a.getValue() < b.getValue();
        });

        // O(K logK)) time, O(1) space
        sort(qs.begin(), qs.end(), [](Query &a, Query &b) {
            return a.getValue() < b.getValue();
        });

        auto getIndex = [cols](int r, int c) {
            return r*cols + c;
        };

        DSU dsu = DSU(n);
        vector<int> answer = vector<int>(qs.size(), 0);
        int start = 0;
        // O(M*N)
        for (int i = 0; i < qs.size(); ++i) {
            while (start < n && nodes[start].getValue() < qs[i].getValue()) {
                int row = nodes[start].getRow();
                int col = nodes[start].getColumn();
                int index = getIndex(row, col);

                if (row-1 >= 0 && grid[row-1][col] <= grid[row][col]) {
                    dsu.unionfind(index, getIndex(row-1, col));
                }

                if (row+1 < rows && grid[row+1][col] <= grid[row][col]) {
                    dsu.unionfind(index, getIndex(row+1, col));
                }

                if (col-1 >= 0 && grid[row][col-1] <= grid[row][col]) {
                    dsu.unionfind(index, getIndex(row, col-1));
                }

                if (col+1 < cols && grid[row][col+1] <= grid[row][col]) {
                    dsu.unionfind(index, getIndex(row, col+1));
                }
                start++;
            }

            if (qs[i].getValue() > grid[0][0]) {
                answer[qs[i].getIndex()] = dsu.getConnectedCount(0);
            }
        }
        return answer;
    }
};