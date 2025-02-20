class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> track;
	    for(int i = 0; i < nums.size(); i++) {
	        int complement = target - nums[i];
	        if(track.find(complement) != track.end()) {
	            return {i, track[complement]};
            }
            track[nums[i]] = i;
        }
        return {-1, -1};
    }
};

// TC - O(n)
// SC - O(n)