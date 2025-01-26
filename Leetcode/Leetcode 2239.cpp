class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int position = -1, minDiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            int diff = abs(nums[i]);
            if(diff < minDiff) {
                minDiff = diff;
                position = i;
            } else if(diff == minDiff) {
                position = (nums[position] < nums[i]) ? i : position;
            }
        }
        return nums[position];
    }
};

//Runtime - 0ms
//Memory - 23.29Mb