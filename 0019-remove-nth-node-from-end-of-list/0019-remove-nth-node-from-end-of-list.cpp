class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;

        while (curr != NULL) {
            len++;
            curr = curr->next;
        }
        int target = len - n;
        if (target == 0) {
            return head->next;
        }
        curr = head;

        for (int i = 1; i < target; i++) {
            curr = curr->next;
        }
        curr->next = curr->next->next;

        return head;
    }
};