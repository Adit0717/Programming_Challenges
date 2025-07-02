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
    ListNode* oddEvenList(ListNode* head) {
        vector<ListNode*> oddNodes;        
        vector<ListNode*> evenNodes;

        ListNode* temp = head;        
        
        int count = 1, i = 0;
        
        while(temp != nullptr) {            
            if(count % 2 == 1) {
                oddNodes.push_back(temp);
            } else {
                evenNodes.push_back(temp);
            }
            temp = temp->next;
            count++;            
        }

        ListNode* dummy = new ListNode(0);
        temp = dummy;

        while(i < oddNodes.size()) {
            temp->next = oddNodes[i];
            i++;
            temp = temp->next;
        }
        
        i = 0;
        
        while(i < evenNodes.size()) {
            temp->next = evenNodes[i];
            i++;
            temp = temp->next;
        }
        temp->next = nullptr;
        return dummy->next;
    }

    ListNode* oddEvenListOpt(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* oddPtr = head;
        ListNode* evenPtr = head->next;
        ListNode* ref = evenPtr;

        while(oddPtr != nullptr && oddPtr->next != nullptr && evenPtr != nullptr && evenPtr->next != nullptr) {
            oddPtr->next = oddPtr->next->next;
            oddPtr = oddPtr->next;
            evenPtr->next = evenPtr->next->next;
            evenPtr = evenPtr->next;
        }
        oddPtr->next = ref;
        
        return head;
    }
};
//TC - O(n)
//SC - O(1)