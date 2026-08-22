class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // Make a copy of the original list
        ListNode* copy = new ListNode(head->val);
        ListNode* temp = copy;
        ListNode* curr = head->next;

        while (curr != NULL) {
            temp->next = new ListNode(curr->val);
            temp = temp->next;
            curr = curr->next;
        }

        // Reverse the copied list
        ListNode* last = reverseList(copy);

        // Compare original and reversed copy
        ListNode* first = head;

        while (first != NULL && last != NULL) {
            if (first->val != last->val) {
                return false;
            }

            first = first->next;
            last = last->next;
        }

        return true;
    }
};