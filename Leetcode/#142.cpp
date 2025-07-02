/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> track;
        int index = 0;
        ListNode* temp = head;
        
        while(temp != nullptr) {                        
            if(track.find(temp) != track.end()) {
                return temp;
            }
            track[temp] = index;
            index++;
            temp = temp->next;
        }
        return nullptr;
    }
    //TC - O(n)
    //SC - O(n)

    
};
