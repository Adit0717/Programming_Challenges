/*
Find Missing Elements

You are given an integer array nums consisting of unique integers.
Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
The smallest and largest integers of the original range are still present in nums.
Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

Example 1:

Input: nums = [1,4,2,5]

Output: [3]

Explanation:
The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;

        sort(nums.begin(), nums.end());

        int j = 0, l = nums[0], r = nums[nums.size() - 1];
        for(int i = l; i <= r; i++) {            
            while(i != nums[j]) {
                result.push_back(i);
                i++;
            }
            j++;
        }
        
        return result;
    }
};
