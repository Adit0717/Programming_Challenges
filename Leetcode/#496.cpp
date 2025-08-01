class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), 0);        

        for(int i = 0; i < nums1.size(); i++) {
            int j = 0;
            while(j < nums2.size() && nums1[i] != nums2[j]) {
                j++;
            }

            if(j == nums2.size() - 1) {
                result[i] = -1;
                continue;
            }

            int k = j + 1;
            while(k < nums2.size() - 1 && nums2[k] <= nums2[j]) {
                k++;
            }

            if(nums2[j] < nums2[k]) result[i] = nums2[k];
            else result[i] = -1;
        }

        return result;
    }
    //TC - O(n^2)
    //SC - O(n)

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int, int> mp;
        stack<int> temp;
        
        for(int i = nums2.size() - 1; i >= 0; i--) {
            if(i == nums2.size() - 1) {
                mp[nums2[i]] = -1;
                temp.push(nums2[i]);
                continue;
            }

            int top = temp.top();
            
            while(top < nums2[i]) {
                temp.pop();                
                if(temp.empty()) {
                    mp[nums2[i]] = -1;
                    temp.push(nums2[i]);
                    break;
                }
                top = temp.top();
            }
            
            top = temp.top();

            if(nums2[i] < top) {
                mp[nums2[i]] = top;
                temp.push(nums2[i]);
            } else mp[nums2[i]] = -1;
        }

        for(int i = 0; i < nums1.size(); i++) {
            int num = nums1[i];

            result.push_back(mp[num]);
        }
        
        return result;
    }
    //TC - O(m + n)
    //SC - O(2m + n)
};