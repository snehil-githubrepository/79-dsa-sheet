class Solution {
public:
    //TC : O(N)
    //SC : O(1)

    //tortoise and Hare method
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow -> next;
            fast = fast->next->next;
        }

        return slow;
    }
}