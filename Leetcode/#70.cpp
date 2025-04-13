class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1)
            return n;
        int one = 1, two = 1, count = 0;
        for(int i = n - 2; i >= 0; i--) {
            count = one + two;
            two = one;
            one = count;
        }
        return count;
    }

    int climbStairs(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        int total = climbStairs(n - 1) + climbStairs(n - 2);
        return total;
    }
    //Brute force recusive solution
    //TC - O(2 ^ n)
    //SC - O(n)

    int solve(vector<int> &dp, int n) {
        if(n < 0) return 0;
        if(n == 0) return 1;

        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return solve(dp, n);
    }
    //TC - O(n)
    //SC - O(n)
};