class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0) {
            int digit = x % 10;
            if(result > INT_MAX/10 || result < INT_MIN/10){
                return 0;
            }
            result = result * 10 + digit;
            x /= 10;
        }
        return result;
    }
};
//result * 10 > INT_MAX || result * 10 < INT_MIN
//trick lies in comparing result and INT_MAX/10