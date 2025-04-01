class Solution {
public:
	int recursiveBinarySearch(int target, vector<int> &nums, int low, int high) {
		int low = 0, high = nums.size() - 1;
		int mid = low + (high - low)/2;

		if(low > high) {
			return -1;
		} // this is important.

		if(target == nums[mid]) {
			return mid;
		}
		if(target > nums[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}

		return recursiveBinarySearch(target, nums, low, high);
	}

	int iterativeBinarySearch(int target, vector<int> &nums) {
		int low = 0, high = nums.size() - 1;		

		while(left <= right) {
			int mid = low + (high - low)/2;
			if(target == nums[mid]) {
				return mid;
			} else if(target > nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}			
		return -1;
	}

	int lowerBound(int target, vector<int> &nums) {
		int low = 0, high = nums.size() - 1, ans = nums[nums.size() - 1];
		while(low <= high) {
			int mid = low + (high - low)/2;
			if(nums[mid] >= target) {
				ans = mid; 
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return ans;
	}

	int upperBound(int target, vector<int> &nums) {
		int low = 0, high = nums.size() - 1, ans = nums[nums.size() - 1];
		while(low <= high) {
			int mid = (low + high) / 2;
			if(nums[mid] <= target) {
				low = mid + 1;
			} else {
				ans = mid;
				high = mid - 1;
			}
		}
		return ans;
	}
};
//Recursive implementaion of binary search
/*
nums = [0,1,2,3,4,5,6,7,8] target = 3
stack = [bs(0, 9) -> bs(0, 3) -> bs(2, 3) -> 3 <= bs(3, 3)]
TC - O(logn)
SC - O(1) + O(logn)

int mid = (l + r) / 2;
l = INT_MAX; r = 1;

int mid = l + (r - l)/2;
*/