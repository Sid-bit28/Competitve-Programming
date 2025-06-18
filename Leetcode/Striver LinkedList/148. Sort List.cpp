/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* l = head;
        ListNode* r = head;
        while (r->next != NULL) {
            r = r->next;
        }

        auto find_mid = [&](ListNode * ll, ListNode * rr)->ListNode* {
            ListNode* fast = ll;
            ListNode* slow = ll;
            while (fast != rr && fast->next != rr) {
                fast = fast->next->next;
                slow = slow->next;
            }
            return slow;
        };
        auto rec = [&](auto rec, ListNode * ll, ListNode * rr)->void{
            if (ll == rr) {
                return;
            }
            ListNode* mid = find_mid(ll, rr);
            rec(rec, ll, mid);
            rec(rec, mid->next, rr);
            ListNode* i = ll; ListNode* j = mid->next;
            while (i != mid && j != rr) {
                if (i->val <= j->val) {
                    i = i->next;
                } else {
                    ListNode* temp = i->next;
                    ListNode* tempp = j;
                    i->next = tempp;
                    tempp->next = temp;
                    j = j->next;
                }
            }
            while (i != mid) {
                i = i->next;
            }
            while (j != rr) {
                i->next = j;
                j = j->next;
            }
            return;
        };
        rec(rec, l, r);
        return head;
    }
};