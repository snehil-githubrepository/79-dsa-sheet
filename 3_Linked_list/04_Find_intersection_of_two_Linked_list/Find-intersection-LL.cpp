class Solution {
    public : 
        //TC : o(2M) ; {M being the biggest linked list}
        //SC : O(1)
        ListNode* findIntersectionLinkedList(ListNode* headA, ListNode* headB) {
            if(headA == NULL || headB == NULL) return NULL;

            //dummy nodes
            ListNode* a = headA; 
            ListNode* b = headB;

            while(a != b) {
                //even if no intersection they will both meet at NULL , that's what we know of! 
                a = a == NULL ? headB : a->next;
                b = b == NULL ? headA : b->next;
            }
            return a;
        }
};