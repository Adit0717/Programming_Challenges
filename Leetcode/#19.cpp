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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        for(int i = 0; i < n; i++) {
            fastPtr = fastPtr->next;
        }
        
        if(fastPtr == nullptr) {
            return head->next;
        }

        while(fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }

        slowPtr->next = slowPtr->next->next;
        return head;
    }
};
//TC - O(n)
//SC - O(1)