class Solution {
	int solve(vector<int> &nums, int index, int prev) {		
		if(index == nums.size()) return 0;		
		int len = 0 + solve(nums, index + 1, prev);
		if(prev == -1 || nums[prev] < nums[index]) {
			len = max(len, 1 + solve(nums, index + 1, index));
		}
		return len;
	}
	int longestSequence(vector<int>& nums) {
		return solve(nums, 0, -1);
	}
}; 

class Solution {
	int longestSequence(vector<int>& nums) {

	}
};