#include <queue>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> bfs_q;
        bfs_q.push(root);
        Node* prevNode;
        
        while (!bfs_q.empty()) {
            int levelSize = bfs_q.size();
            prevNode = nullptr;
            
            for (int i = 0; i < levelSize; ++i) {
                auto cur = bfs_q.front();
                bfs_q.pop();
                if (cur->left != nullptr) bfs_q.push(cur->left);
                if (cur->right != nullptr) bfs_q.push(cur->right);
                
                if (prevNode != nullptr) {
                    prevNode->next = cur;
                }
                prevNode = cur;
            }
        }
        return root;
    }
};
