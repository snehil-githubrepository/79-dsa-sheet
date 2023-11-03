class Solution {
public:
    //TC : O(N)
    //SC : O(1)

    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;

        ListNode* slow = head, *fast = head;

        while(fast -> next != NULL && fast -> next -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true; 
        }
        return false;
    }
};