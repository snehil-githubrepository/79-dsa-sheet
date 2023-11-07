class Solution {
    public : 
        ListNode* sortList(ListNode* head) {
            if(head == NULL) return NULL;

            vector<int> storedList;
            ListNode* dummy = head;

            while(dummy != NULL) {
                storedList.push_back(dummy->val);
                dummy = dummy->next;
            }

            sort(storedList.begin(), storedList.end());

            dummy = head;
            int i = 0;

            while(dummy != NULL) {
                dummy -> val = storedList[i];
                dummy = dummy -> next;
                i++;
            }

            return head;
        }
}