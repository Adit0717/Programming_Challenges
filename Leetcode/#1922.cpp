class Solution {
public:
    long long powerCalc(long long base, long long exp) {
        if(exp == 0)
            return 1;
        return (base * powerCalc(base, exp - 1)) % MOD;
    }
    long long countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2, oddCount = n / 2;
        return powerCalc(5, evenCount) * powerCalc(4, oddCount);
    }
};
//TC - O(evenCount + oddCount) ~ O(n)
//SC - O(max(evenCount, oddCount)) ~ O(n)

class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long powerCalc(long long base, long long exp) {
        if(exp == 0)
            return 1;
        if(exp % 2 == 0)
            return powerCalc((base * base) % MOD, exp / 2);

        return base * powerCalc((base * base) % MOD, (exp - 1) / 2) % MOD;
    }
    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2, oddCount = n / 2;
        return (powerCalc(5, evenCount) * powerCalc(4, oddCount)) % MOD;
    }
};
//TC - O(logn)
//SC - O(logn)

/*
Total digits -> (0 - 9) = 10
5 even places and 5 odd places out of that selected 'n'
(5)^(n/2) * (4)^(n/2)
*/