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
    ListNode* mergeLists(ListNode* ref, ListNode* temp) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(temp && ref) {
            if(ref->val <= temp->val) {
                tail->next = ref;
                ref = ref->next;
            } else {
                tail->next = temp;
                temp = temp->next;
            }
            tail = tail->next;
        }

        if(ref) tail->next = ref;
        if(temp) tail->next = temp;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;

        int i = 0;

        while(i < lists.size() && lists[i] == nullptr) {
            i++;
        }

        if(i == lists.size()) return nullptr;

        ListNode* ref = lists[0];
        ListNode* head = ref;
        
        for(int j = i + 1; j < lists.size(); j++) {
            if(lists[j] == nullptr) continue;
            
            ListNode* temp = lists[j];
            head = mergeLists(ref, temp);
            ref = head;
        }
        return head;
    }
    // TC - O(n^3)

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, 
        vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        for(int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                auto ele = lists[i];
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while(!pq.empty()) {
            auto ele = pq.top();
            pq.pop();
            if(ele.second->next) {
                pq.push({ele.second->next->val, ele.second->next});
            }
            temp->next = ele.second;
            temp = temp->next;
        }
        return dummy->next;
    }
    //TC - O(Nlogk)
    //SC - O(k)
};
