/*
Q1. Remove Zeros in Decimal Representation
You are given a positive integer n.

Return the integer obtained by removing all zeros from the decimal representation of n.
*/

class Solution {
public:
    long long removeZeros(long long n) {
        long long result = 0;
        string exp = to_string(n);

        for(char c : exp) {
            if(c == '0') continue;
            int num = c - '0';
            result = result * 10 + num;
        }            
        
        return result;
    }
};

/*
Q2. Maximum Alternating Sum of Squares
You are given an integer array nums. You may rearrange the elements in any order.

The alternating score of an array arr is defined as:

score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
*/

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long firstHalf = 0, secondHalf = 0;
        
        for(int &x : nums) {
            x = x * x;
        }
        
        sort(nums.begin(), nums.end());        
        
        for(int i = 0; i < (nums.size() / 2); i++) {
            firstHalf += nums[i];
        }

        for(int i = nums.size() / 2; i < nums.size(); i++) {
            secondHalf += nums[i];
        }
        
        return secondHalf - firstHalf;
    }
};