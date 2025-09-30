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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr && curr->next) {
            ListNode* first = curr;
            ListNode* second = curr->next;

            first->next = second->next;
            prev->next = second;
            second->next = first;

            prev = first;
            curr = first->next;            
        }
        return dummy->next;
    }
};