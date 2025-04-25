class Solution {
	long solve(vector<int> &nums, int buy, int index, 
			   vector<vector<int>> dp) {
		if(index == nums.size()) return 0;
		if(dp[index][buy] != -1) return dp[index][buy];

		long profit = 0;
		if(buy == 1) {
			profit = max(-nums[index] + solve(nums, 0, index + 1), 
						 0 + solve(nums, 1, index + 1));
		} else {
			profit = nums[index] + solve(nums, 1, index + 1);
		}
		return dp[index][buy] = profit;
	}

	long stockProfit(vector<int> &nums) {
		vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
		return solve(nums, 1, 0, dp);
	}

	long solveBF(vector<int>& nums, int index, int buy) {
		int profit = 0;
		if(index == nums.size()) return 0;

		if(buy == 1) {
			profit = max(-nums[index] + solve(nums, index + 1, 0),
						 0 + solve(nums, index + 1, 1));
		} else {
			profit = nums[index] + solve(nums, index + 1, 1);
		}

		return profit;
	}

	long stockProfitBF(vector<int>& nums) {
		return solve(nums, 0, 1);
	}
};
//BF TC - O(2^n) SC - O(n)
//MEMO TC - O(n*2) = O(n) SC - O(n*2) = O(n)