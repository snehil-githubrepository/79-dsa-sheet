class Solution {
public:
    //TC : O(N)
    //SC : O(1)

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * start = new ListNode(); //dummy node that points to head as said in optimized approach
        start -> next = head; 
        ListNode* fast = start; //assign fast and slow to the dummy node
        ListNode* slow = start; //assign fast and slow to the dummy node

        for(int i = 1; i <= n; ++i)
            fast = fast->next; //move fast by the n we have in question at first
    
        while(fast->next != NULL) //till fast reaches end of list
        {
            fast = fast->next; 
            slow = slow->next;
        }
        
        slow->next = slow->next->next; //break the link
        
        return start->next; //dummy -> next (covers up the edge case too)
    }
};