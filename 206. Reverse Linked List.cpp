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
    public ListNode reverseList(ListNode head) 
    {
        if(head == null)
        {
            return head;
        }
        if(head.next == null)
        {
            return head;
        }
        ListNode curNode = head;
        ListNode nextNode = curNode.next;
        curNode.next = null;
        for(;nextNode!=null;)
        {
            ListNode tempNode = curNode;
            curNode = nextNode;
            nextNode =  curNode.next;
            curNode.next = tempNode;
        }
        return curNode;
    }

}