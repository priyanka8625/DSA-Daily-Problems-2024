/*
class Node {
    int data;
    Node next;
    
    public Node (int data){
        this.data = data;
        this.next = null;
    }
}
*/

class Solution {
    
    public Node sort(Node head){
         //your code here, return the head of the sorted list
         if(head == null || head.next == null)
             return head;
         
         ArrayList<Integer> list = new ArrayList<>();
         Node temp = head;
         while(temp != null){
             list.add(temp.data);
             temp = temp.next;
         }
         Collections.sort(list);
         temp = head;
         for(Integer i:list){
             temp.data = i;
             temp = temp.next;
         }
         return head;
    }
 }