/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
public:
  // Function to delete a node at given position.
  Node* deleteNode(Node* head, int x) {
    Node* dummy = new Node(-1);
    dummy->next = head;
    if (head) head->prev = dummy;

    int count = 0;
    Node* temp = dummy;
    while (temp != NULL && count < x) {
      temp = temp->next;
      count++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;

    delete(temp);

    Node* result = dummy->next;
    if (result) result->prev = NULL;
    delete(dummy);
    return result;
  }
};