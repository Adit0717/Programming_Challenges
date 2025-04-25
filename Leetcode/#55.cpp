class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        
        int maxIndex = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxIndex) return false;
            maxIndex = max(maxIndex, nums[i] + i);
            if(maxIndex >= nums.size() - 1)
                return true;
        }
        return true;
    }
    //TC - O(n)
    //SC - O(1)

    bool solve(vector<int>& nums, int index) {
        if(index >= nums.size() - 1) {
            return true;
        }

        for(int i = 1; i <= nums[index]; i++) {
            if(solve(nums, i + index)) {
                return true;
            }
        }

        return false;
    }

    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }
    //TC - O(2^n)
    //SC - O(1)

    bool solve(vector<int>& nums, vector<int>& dp, int index) {
        if(index >= nums.size() - 1) {
            return true;
        }
        if(dp[index] != -1) {
            return dp[index];
        }

        int limit = min(nums.size() - 1, index + nums[index]);

        for(int i = index + 1; i <= limit; i++) {
            if(solve(nums, dp, i)) {
                return dp[index] = 1;
            }
        }
        return dp[index] = 0;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, dp, 0);
    }
};
