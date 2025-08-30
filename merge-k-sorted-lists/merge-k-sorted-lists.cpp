#include <iostream>
#include <list>
#include <queue>
#include <vector>

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
        ListNode* sentinel_head = new ListNode(0);
        ListNode* head = sentinel_head;
        
        priority_queue<ListNode*, vector<ListNode*>, comparator> minheap;
        
        for (auto list : lists) {
            if (list != nullptr) {
                minheap.push(list);
            }
        }
        
        while (!minheap.empty()) {
            auto curnode = minheap.top();
            minheap.pop();
            
            head->next = curnode;
            head = head->next;
            
            curnode = curnode->next;
            if (curnode != nullptr) minheap.push(curnode);
        }
        head = sentinel_head->next;
        delete sentinel_head;
        return head;
    }
};
