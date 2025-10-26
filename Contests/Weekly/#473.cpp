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

/*
Q3. Stable Subarrays With Equal Boundary and Interior Sum
You are given an integer array capacity.

A subarray capacity[l..r] is considered stable if:

Its length is at least 3.
The first and last elements are each equal to the sum of all elements strictly between them (i.e., capacity[l] = capacity[r] = capacity[l + 1] + capacity[l + 2] + ... + capacity[r - 1]).
Return an integer denoting the number of stable subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.
*/
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        long long result = 0;
        if(capacity.size() < 3) return 0;

        vector<long long> prefixSums(capacity.size() + 1, 0);
        for(int i = 0; i < capacity.size() - 1; i++) {
            prefixSums[i + 1] = prefixSums[i] + capacity[i];
        }

        for(int i = 0; i < capacity.size() - 2; i++) {
            for(int j = i + 2; j < capacity.size(); j++) {
                long long val = capacity[i];

                if(val != capacity[j]) continue;

                long long sum = prefixSums[j] - prefixSums[i + 1];

                if(sum == val) result++;
            }
        }
        
        return result;
    }
}; //Brute force

