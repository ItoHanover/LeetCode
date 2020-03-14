//JAVA
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        if (node == null) return;
        ListNode curNode = node.next;
        node.val = curNode.val;
        node.next = curNode.next;
    }
}