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