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
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (ListNode* node : lists) {
            if (node != NULL) {
                q.push(node);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!q.empty()) {
            ListNode* temp = q.top();
            q.pop();

            tail->next = temp;
            tail = tail->next;

            if (temp->next != NULL) {
                q.push(temp->next);
            }
        }
        return dummy->next;
    }
};