class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= nums.size() - 1 && nums[i] != nums[nums[i] - 1]) {                  
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> track(nums.begin(), nums.end());
        for(int i = 1; i <= track.size(); i++) {
            if(track.find(i) == track.end()) {
                return i;
            }
        }
        return track.size() + 1;
    }
};
/*
min and max values of the given input
[7, -2, 3, 1, 2, 20, -5]
[-5, -2, 3, 1, 2, 20, 7]
[-5, -2, 3, 1, 2, 20, 7]
[-5, -2, 3, 1, 2, 20, 7]
[1, -2, 3, -5, 2, 20, 7]
[1, 2, 3, -5, -2, 20, 7]
[1, 2, 3, -5, -2, 20, 7]
Ignore -ve, out of range numbers and numbers already in correct position
Idea is to place the numbers on to its correct position
*/
