class Solution {
	int solve(vector<int>& nums, int index) {
		if(index < 0) return 0;
		if(index == 0) return nums[0];

		nums[index] = max(nums[index] + solve(nums, index - 2),
						  0 + solve(nums, index - 1));
		return nums[index];
	}
	int houseRobber(vector<int>& nums) {
		return solve(nums, nums.size() - 1);
	}
};
//TC - O(2 ^ n)
//SC - O(n) - recursive call stack

class Solution {
	int solve(vector<int> &nums, vector<int> &dp, int index) {
		if(index < 0) return 0;
		if(index == 0) return nums[0];

		if(dp[index] != -1) return dp[index];

		return dp[index] = max(nums[index] + solve(nums, dp, index - 2), 
							   solve(nums, dp, index - 1));
	}
	int houseRobber(vector<int>& nums) {
		vector<int> dp(nums.size(), -1);
		return solve(nums, dp, nums.size() - 1);
	}
	//TC - O(n)
	//SC - O(n + n)
};

class Solution {
	
}