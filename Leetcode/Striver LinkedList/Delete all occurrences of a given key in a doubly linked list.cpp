// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
public:
   void deleteAllOccurOfX(struct Node** head_ref, int x) {
      Node* dummy = new Node(-1);
      dummy->next = head;
      if (head) head->prev = dummy;

      Node* temp = dummy;
      while (temp != NULL) {
         if (temp->data == x) {
            Node* curr = temp;
            curr->prev->next = curr->next;
            if (curr->next) curr->next->prev = curr->prev;
            delete(curr);
         }
         temp = temp->next;
      }

      head_ref = dummy->next;
      if (head_ref) head_red->prev = NULL;
      delete(dummy);
   }
};