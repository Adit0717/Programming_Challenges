class Solution {
public: 
    int majorityElement(vector<int> &nums) {
        int maxEle = INT_MIN, count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                count++;
                maxEle = nums[i];
                continue;
            }

            if(maxEle != nums[i]) {
                count--;
            } else {
                count++;
            }
        }
        return maxEle;
    }
};