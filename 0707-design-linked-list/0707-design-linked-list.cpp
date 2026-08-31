class MyLinkedList {
public:
    ListNode* head;

    MyLinkedList() {
        head = new ListNode();   // dummy node
    }

    int get(int index) {
        ListNode* curr = head->next;

        while (curr != NULL && index > 0) {
            curr = curr->next;
            index--;
        }

        if (curr == NULL)
            return -1;

        return curr->val;
    }

    void addAtHead(int val) {
        ListNode* temp = new ListNode(val);

        temp->next = head->next;
        head->next = temp;
    }

    void addAtTail(int val) {
        ListNode* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        ListNode* temp = new ListNode(val);
        curr->next = temp;
    }

    void addAtIndex(int index, int val) {

        if (index < 0)
            return;

        ListNode* prev = head;

        while (prev != NULL && index > 0) {
            prev = prev->next;
            index--;
        }

        if (prev == NULL)
            return;

        ListNode* temp = new ListNode(val);

        temp->next = prev->next;
        prev->next = temp;
    }

    void deleteAtIndex(int index) {

        if (index < 0)
            return;

        ListNode* prev = head;

        while (prev->next != NULL && index > 0) {
            prev = prev->next;
            index--;
        }

        if (prev->next == NULL)
            return;

        ListNode* temp = prev->next;
        prev->next = temp->next;

        delete temp;
    }
};