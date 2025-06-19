// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        Node* temp = head;
        map<int, int> mp;
        vector<pair<int, int>> ans;
        while (temp != NULL) {
            int val = target - (temp->data);
            if (mp.find(val) != mp.end()) {
                ans.push_back({min(temp->data, val), max(temp->data, val)});
            }
            mp[temp->data]++;
            temp = temp->next;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};