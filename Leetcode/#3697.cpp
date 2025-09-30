class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> result;
        int i = 1;
        
        while(n > 0) {
            int digit = n % 10;
            int number = digit * i;
            if(number != 0) result.push_back(number);
            n /= 10;
            if(i < INT_MAX / 10) i *= 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
//TC - O(d)
//SC - O(d)