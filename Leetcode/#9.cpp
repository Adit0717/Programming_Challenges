class Solution {
public:
    bool isPalindrome(int x) {
        int duplicate = x;
        long rev = 0;
        while(x > 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }
        return duplicate == rev;
    }
};
//TC - O(log 10 (x))
//SC - O(1)