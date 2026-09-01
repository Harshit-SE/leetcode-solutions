class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        Node* dummy = new Node();
        Node* prev = dummy;

        stack<Node*> st;
        st.push(head);

        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            curr->prev = prev;
            prev->next = curr;
            if (curr->next != NULL) {
                st.push(curr->next);
            }
            if (curr->child != NULL) {
                st.push(curr->child);
            }
            curr->child = NULL;
            prev = curr;
        }
        dummy->next->prev = NULL;
        return dummy->next;
    }
};