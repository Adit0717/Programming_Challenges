class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> count;

        for(int x : nums) {
            if(count.find(x) == count.end()) {
                count.insert(x);
            } else {
                return true;
            }
        }
        return false;
    }
};

// TC - O(n)
// SC - O(n)