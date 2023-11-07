class Solution {
public:
    //TC : o(n)
    //SC : O(1)
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        //first node is considered odd (question)
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* HeadOfEven = head->next;

        while(even != NULL && even ->next != NULL) {
            //put odd in odd List
            odd->next = odd->next->next;

            //move pointer to next odd node
            odd = odd->next;

            //even to even List
            even -> next = even->next->next;

            //move pointer to next even node
            even = even -> next;
        }

        //as odd finishes we put next of last odd node to HeadOfEven
        odd->next=HeadOfEven;

        return head;
    }
};