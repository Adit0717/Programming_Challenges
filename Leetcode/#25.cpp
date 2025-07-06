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
    ListNode* kthNode(ListNode* temp, int k) {
        while(temp && k > 1) {
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverse(ListNode* temp) {
        ListNode* prev = nullptr;
        ListNode* curr = temp;
        ListNode* after = curr;

        while(curr) {
            after = after->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;
        
        while(temp != nullptr) {
            ListNode* kNode = kthNode(temp, k);            

            if(kNode == nullptr) {
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* ref = kNode->next;
            kNode->next = nullptr;
            ListNode* newNode = reverse(temp);

            if(temp == head) {
                head = kNode;
            } else {
                prevNode->next = kNode;
            }

            prevNode = temp;
            temp = ref;
        }
        return head;
    }
};
// Traverse upto k nodes; disconnect the node and reverse it. 
// And then in the next iteration connect the previous node to the next kth node.
//TC - O(n)