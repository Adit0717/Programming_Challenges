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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* after = curr;

        while(after){
            after = after -> next;
            curr -> next = prev;
            prev = curr;
            curr = after;            
        }
        return prev;
    }
    //Recursive
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* newHead = reverseList(head->next);

        ListNode* temp = head->next;
        temp->next = head;
        head->next = nullptr;

        return newHead;
    }
};
//TC - O(n)
//SC - O(n) for recursion