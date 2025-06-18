/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
  // Function to reverse a doubly linked list
  DLLNode* reverseDLL(DLLNode* head) {
    DLLNode* prev = NULL;
    DLLNode* curr = head;
    while (curr != NULL) {
      DLLNode* nxt = curr->next;
      curr->next = prev;
      if (curr->next != NULL) curr->next->prev = curr;
      prev = curr;
      curr = nxt;
    }
    return prev;
  }
};