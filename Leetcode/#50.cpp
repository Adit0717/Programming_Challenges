class Solution {
public:
    double pow(double x, long long n) {
        if(n == 0)
            return 1;
        if(n % 2 == 0) {
            return pow(x * x, n/2);
        }
        return x * pow(x * x, (n - 1) / 2);
    }
    double myPow(double x, int n) {
        long long N = n;        
        if(N < 0) {
            x = 1/x;
            N = -N;
        } // convert the base before calling
        double result = pow(x, N);
        return result;
    }
    //Recursive Brute Force & optimal
    //TC - O(logn)
    //SC - O(n)
    //TC - O(logn)
    //SC - O(logn)

    double myPow1(double x, int n) {
        double answer = 1.0;
        long long N = n;
        if(N < 0) {
            x = 1/x;
            N = -N;
        }
        while(N > 0) {
            if(N % 2 == 0) {
                x = x * x;
                N /= 2;
            } else {
                answer = answer * x;
                N -= 1;
            }
        }        
        return answer;
    }
    //TC - O(logN)
    //SC - O(1)
};