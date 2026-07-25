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
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1 = reverseLL(l1);
        ListNode* head2 = reverseLL(l2);
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        while (head1 != NULL || head2 != NULL) {
            ListNode* temp = new ListNode(0);
            int x = (head1? head1->val : 0);
            int y = (head2? head2->val : 0);
            temp->val = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
            prev->next = temp;
            prev = temp;
        }
        if(carry){
            prev->next = new ListNode(carry);
        }
        return reverseLL(dummy->next);
    }
};