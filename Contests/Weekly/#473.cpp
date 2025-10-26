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