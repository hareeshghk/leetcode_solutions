/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(new Comparator<ListNode>() {
            public int compare(ListNode a1, ListNode a2) {
                
                if (a1.val > a2.val) {
                    return 1;
                } else if (a1.val == a2.val) {
                    return 0;
                } else {
                    return -1;
                }
            }
        });
        
        for (ListNode node : lists) {
            if (node != null) {
                pq.add(node);
            }
        }
        
        ListNode root = new ListNode(-1);
        
        ListNode temp = root;
        
        while(!pq.isEmpty()) {
            ListNode current = pq.poll();
            
            temp.next = current;
            temp = current;
            
            if (current.next != null) {
                pq.add(current.next);
            }
        }
        
        return root.next;
    }
}