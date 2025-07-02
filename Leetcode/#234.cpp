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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> track;

        while(temp != nullptr) {
            track.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while(temp != nullptr) {
            int topEle = track.top();
            track.pop();

            if(temp->val != topEle) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slowPtr;
        ListNode* after = curr;

        while(curr != nullptr) {
            after = after->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }

        ListNode* temp = head;
        ListNode* tail = prev;

        while(tail != nullptr) {
            if(temp->val != tail->val) {
                return false;
            }
            temp = temp->next;
            tail = tail->next;
        }

        return true;
    }
};
//TC - O(n)
//SC - O(n) - for stack