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
    public int pairSum(ListNode head) {
        Stack<Integer> st = new Stack<>();
        
        ListNode slowPointer=head, fastPointer=head;
        
        while (fastPointer != null && fastPointer.next != null) {
            st.add(slowPointer.val);
            slowPointer = slowPointer.next;
            fastPointer = fastPointer.next.next;
        }
        
        int answer = 0;
        while (slowPointer != null) {
            answer = Math.max(answer, st.pop() + slowPointer.val);
            slowPointer = slowPointer.next;
        }
        
        return answer;
    }
}