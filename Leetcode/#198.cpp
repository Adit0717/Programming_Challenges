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
	int houseRobber(vector<int>& nums) {
		vector<int> dp(nums.size());
		
		dp[0] = nums[0];

		for(int i = 1; i < nums.size(); i++) {
			int take = nums[i];
			if(i > 1) take += dp[i - 2];
			int dontTake = dp[i - 1];
			dp[i] = max(take, dontTake);
		}
		return dp[nums.size() - 1];
	}
}

class Solution {	
	int houseRobber(vector<int>& nums) {		
		int prev2 = 0;
		int prev1 = nums[0];

		for(int i = 1; i < nums.size(); i++) {
			int take = nums[i];
			if(i > 1) take += prev2;
			int dontTake = prev1;
			int curr = max(take, dontTake);

			prev2 = prev1;
			prev1 = curr;						
		}
		return prev1;
	}
}