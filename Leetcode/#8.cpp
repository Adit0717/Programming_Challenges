class Solution {
public:
    int myAtoi(string s) {
        int result = 0, i = 0;
        int sign = 1;

        while(s[i] == ' ') {
            i++;
        }

        if(i < s.size() && s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while(isdigit(s[i]) && i < s.size()) {            
            int digit = s[i] - '0';
            if(result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + digit;
            i++;
        }
        return result * sign;
    }
};