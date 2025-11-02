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

/*
Maximum Product of Three Elements After One Replacement
You are given an integer array nums.
You must replace exactly one element in the array with any integer value in the range [-10^5, 10^5] (inclusive).
After performing this single replacement, determine the maximum possible product of any three elements 
at distinct indices from the modified array.

Return an integer denoting the maximum product achievable.

Input: nums = [-5,7,0]
Output: 3500000
Explanation:
Replacing 0 with -10^5 gives the array [-5, 7, -10^5], 
which has a product (-5) * 7 * (-10^5) = 3500000. 
The maximum product is 3500000.
*/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long result = 0;
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        int temp = 2;
        long long prod = 1;
        
        while(temp > 0) {
            if(abs(nums[l]) >= abs(nums[r])) {
                prod *= nums[l];
                l++;
            } else {
                prod *= nums[r];
                r--;
            }
            temp--;
        }
        result = prod;
        cout << result;
        if(prod < 0) result = result * pow(-10, 5);
        else result = result * pow(10, 5);
        
        return result;
    }
};