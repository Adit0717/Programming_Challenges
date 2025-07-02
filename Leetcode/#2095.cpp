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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return nullptr;
        
        ListNode* prev = nullptr;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        while(fastPtr && fastPtr->next) {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        prev->next = slowPtr->next;

        return head;
    }
};
//TC - O(n)
//SC - O(1)