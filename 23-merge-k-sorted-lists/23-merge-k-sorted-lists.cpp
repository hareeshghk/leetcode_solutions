#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct comparator {
      bool operator()(ListNode* a, ListNode* b) {
          return a->val > b->val;
      }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=nullptr, *tail=nullptr;
        
        priority_queue<ListNode*, vector<ListNode*>, comparator> minheap;
        
        for (auto list : lists) {
            if (list != nullptr) {
                minheap.push(list);
            }
        }
        
        while (!minheap.empty()) {
            auto curnode = minheap.top();
            minheap.pop();
            
            if (head == nullptr) {
                head=tail=curnode;
            } else {
                tail->next = curnode;
                tail = tail->next;
            }
            
            curnode = curnode->next;
            if (curnode != nullptr) minheap.push(curnode);
        }
        return head;
    }
};
