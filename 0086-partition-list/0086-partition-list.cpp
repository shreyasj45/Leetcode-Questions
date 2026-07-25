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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1 = new ListNode(0);
        ListNode* ptr1 = dummy1;
        ListNode* dummy2 = new ListNode(0);
        ListNode* ptr2 = dummy2;
        ListNode* temp = head;
        while (temp != NULL) {
            if (temp->val < x) {
                ptr1->next = new ListNode(temp->val);
                ptr1 = ptr1->next;
            } else {
                ptr2->next = new ListNode(temp->val);
                ptr2 = ptr2->next;
            }
            temp = temp->next;
        }
        ptr1->next = dummy2->next;
        delete dummy2;
        return dummy1->next;
    }
};