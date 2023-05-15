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
    public ListNode swapNodes(ListNode head, int k) {
        int listIndex = 0;
        
        ListNode traverser = head;
        
        ListNode kthNodeFromFirst = null, kthNodeFromLast = null;
        while (traverser != null) {
            listIndex++;
            if (listIndex == k) {
                kthNodeFromFirst = traverser;
            }
            traverser = traverser.next;
        }
        
        int secondK = listIndex-k+1;
        traverser = head;
        listIndex = 0;
        while (traverser != null) {
            listIndex++;
            if (listIndex == secondK) {
                kthNodeFromLast = traverser;
                break;
            }
            traverser = traverser.next;
        }
        
        int temp = kthNodeFromFirst.val;
        kthNodeFromFirst.val = kthNodeFromLast.val;
        kthNodeFromLast.val = temp;
        
        return head;
    }
}