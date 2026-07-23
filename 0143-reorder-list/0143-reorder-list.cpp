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
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* head2 = slow->next;
        slow->next = NULL;
        head2 = reverseLL(head2);
        ListNode* ptr1 = head;
        ListNode* ptr2 = head2;
        while(ptr2!=NULL){
            ListNode* next1 = ptr1->next;
            ListNode* next2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = next1;
            ptr1 = next1;
            ptr2 = next2;
        }
    return;
    }
};