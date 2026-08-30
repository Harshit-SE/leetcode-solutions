class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        int carry = 0;

        while(l1 != NULL || l2 != NULL || carry != 0) {

            int x = 0;
            int y = 0;

            if(l1 != NULL)
                x = l1->val;

            if(l2 != NULL)
                y = l2->val;

            int sum = x + y + carry;

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            if(l1 != NULL)
                l1 = l1->next;

            if(l2 != NULL)
                l2 = l2->next;
        }

        return dummy->next;
    }
};