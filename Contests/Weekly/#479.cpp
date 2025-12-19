/* 2. 
Q2. Largest Prime from Consecutive Prime Sum©leetcode
You are given an integer n.
Return the largest prime number less than or equal to n that can be expressed as the sum of one or more consecutive prime numbers starting from 2. If no such number exists, return 0.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.
*/

class Solution {
public:
    bool checkPrime(int num) {
        if(num <= 1) return false;
        
        for(int i = 2; i * i <= num; i++) {
            if(num % i == 0) return false;
        }
        return true;
    }
    
    int largestPrime(int n) {
        int sum = 0, result = 0;

        for(int i = 2; i <= n; i++) {
            int num = i;

            bool isPrime = checkPrime(num);

            if(!isPrime) continue;
            
            sum += i;
            if(sum > n) {
                sum -= i;
                if(checkPrime(sum)) result = sum;
                break;
            }
            if(checkPrime(sum)) result = sum;
        }
        
        return result;
    }
};