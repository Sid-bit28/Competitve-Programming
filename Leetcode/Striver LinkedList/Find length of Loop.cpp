/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        if (head == NULL) {
            return 0;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                int nodes = 1;
                while (slow->next != fast) {
                    slow = slow->next;
                    nodes++;
                }
                return nodes;
            }
        }
        return 0;
    }
};