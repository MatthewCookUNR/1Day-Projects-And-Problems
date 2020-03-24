import java.util.*;

class LinkedListProbs {
	
    Node head; // head of the list 
    
    /* Linked list Node*/
    class Node { 
        int data; 
        Node next; 
  
        // Constructor to create a new node 
        // Next is by default initialized 
        // as null 
        Node(int d) { data = d; } 
    } 
    
    public static void main(String []args)
    {
    	LinkedListProbs list = new LinkedListProbs();
    	list.head = list.makeList(7);
    	list.reverse();
    	list.printList();
    	System.out.println(list.findMiddle());
    }
    
    public Node makeList(int num)
    {
    	if(num == 0)
    	{
    		return null;
    	}
    	else
    	{
    		head = new Node(0);
    		Node temp = head;
    		for(int i = 0; i < num-1; i++)
    		{
    			temp.next = new Node(i+1);
    			temp = temp.next;
    		}
    		return head;
    	}
    }
    
    public int findMiddle()
    {
    	if(head != null)
    	{
        	Node tempCurrent = head;
        	Node tempTwoNext = head;
        	while(tempTwoNext != null && tempTwoNext.next != null)
        	{
        		tempCurrent = tempCurrent.next;
        		tempTwoNext = tempTwoNext.next.next;
        	}
        	return tempCurrent.data;
    	}
    	
    	return -1;
    }
    
    public void printList()
    {
        Node n = head; 
        while (n != null) 
        { 
            System.out.print(n.data + " "); 
            n = n.next; 
        }
        System.out.println();
    }
    
    public void reverse() 
    {
    	Node prev = null;
    	Node next = null;
    	while(head != null)
    	{
    		next = head.next;
    		head.next = prev;
    		prev = head;
    		head = next;
    	}
    	head = prev;
    }
    
}