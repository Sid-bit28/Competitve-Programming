/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
public:
    Node* segregate(Node* head) {
        Node* dummy = new Node(-1);
        dummy->next = head;

        Node* a = NULL;
        Node* b = NULL;
        Node* c = NULL;
        Node* curr_a = NULL;
        Node* curr_b = NULL;
        Node* curr_c = NULL;
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == 0) {
                if (curr_a == NULL) {
                    curr_a = temp;
                    a = temp;
                } else {
                    curr_a->next = temp;
                    curr_a = curr_a->next;
                }
            } else if (temp->data == 1) {
                if (curr_b == NULL) {
                    curr_b = temp;
                    b = temp;
                } else {
                    curr_b->next = temp;
                    curr_b = curr_b->next;
                }
            } else {
                if (curr_c == NULL) {
                    curr_c = temp;
                    c = temp;
                } else {
                    curr_c->next = temp;
                    curr_c = curr_c->next;
                }
            }
            temp = temp->next;
        }
        Node* curr = dummy;
        if (a != NULL) {
            curr->next = a;
            curr = curr_a;
        }
        if (b != NULL) {
            curr->next = b;
            curr = curr_b;
        }
        if (c != NULL) {
            curr->next = c;
            curr = curr_c;
        }
        curr->next = NULL;
        return dummy->next;
    }
};