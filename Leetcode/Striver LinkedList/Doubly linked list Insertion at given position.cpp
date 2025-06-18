/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
public:
  // Function to insert a new node at given position in doubly linked list.
  Node *addNode(Node *head, int pos, int data) {
    Node* dummy = new Node(-1);
    dummy->next = head;
    if (head) head->prev = dummy;

    Node* temp = dummy;
    int count = 0;
    while (temp && count <= pos) {
      temp = temp->next;
      count++;
    }

    Node* newNode = new Node(data);

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;

    Node* result = dummy->next;
    if (result) result->prev = NULL;
    delete(dummy);
    return result;
  }
};