/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head->next;
        while (temp != NULL) {
            if (temp->prev->data == temp->data) {
                Node* curr = temp;
                temp = temp->next;

                curr->prev->next = curr->next;
                if (curr->next != NULL) curr->next->prev = curr->prev;
                delete(curr);
            } else temp = temp->next;
        }
        return head;
    }
};