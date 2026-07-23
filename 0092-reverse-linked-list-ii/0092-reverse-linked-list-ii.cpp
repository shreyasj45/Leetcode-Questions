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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx=1;
        ListNode* temp = head;
        ListNode* start = NULL;
        while(idx < left){
            if(idx == left - 1){
                start = temp;
            }
            temp = temp->next;
            idx++;
        }
        ListNode* prev = NULL;
        ListNode* curr = temp;
        ListNode* dummy = curr;
        ListNode* next = NULL;
        while(idx <= right){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            idx++;
        }
        dummy->next = curr;

        if(start != NULL){
            start->next = prev;
        }
        else{
            head = prev;
        }
        return head;
    }
};