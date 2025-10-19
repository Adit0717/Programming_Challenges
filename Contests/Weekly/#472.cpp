/*
Q1. Smallest Missing Multiple of K
Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.

A multiple of k is any positive integer divisible by k.

Example 1:

Input: nums = [8,2,3,4,6], k = 2

Output: 10

Explanation:

The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> track;
        for(int x : nums) {
            track.insert(x);
        }
        
        for(int i = 1; i <= 101; i++) {
            if(track.find(k * i) == track.end()) {
                return k * i;
            }
        }
        return k * 102;
    }
};

/*
Q2. Longest Balanced Subarray I
You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [2,5,4,3]

Output: 4

Explanation:

The longest balanced subarray is [2, 5, 4, 3].
It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.©leetcode
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int len = 0, l = 0, r = 0, evenCount = 0, oddCount = 0;
        unordered_set<int> track;
        
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> oddCount;
            unordered_set<int> evenCount;

            for(int j = i; j < nums.size(); j++) {
                int currentNum = nums[j];

                if(currentNum % 2 == 0) evenCount.insert(currentNum);
                else oddCount.insert(currentNum);

                if(oddCount.size() == evenCount.size()) {
                    len = max(len, (j - i) + 1);
                }
            }
        }
        
        return len;
    }
};