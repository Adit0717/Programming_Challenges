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
    int makeCircular(ListNode* head) {
        ListNode* temp = head;
        int length = 1;
        
        while(temp->next) {
            temp = temp->next;
            length++;
        }
        temp->next = head;
        
        return length;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }

        int len = makeCircular(head);
        int rotations = k % len;
        int count = len - rotations - 1;

        ListNode* temp = head;        
        
        while(count > 0) {
            temp = temp->next;
            count--;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};
//TC - O(n + n) ~ O(n)