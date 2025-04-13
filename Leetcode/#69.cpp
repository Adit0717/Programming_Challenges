class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r - l) / 2;            
            if(mid == x / mid) {
                return mid;
            } else if(mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};
//TC - O(logn)

class Solution {
public:
    int mySqrt(int x) {
        int result = 0;
        if(x <= 1)
            return x;
        for(int i = 1; i <= x/2; i++) {
            if(i <= x / i) {
                result = max(result, i);
            }
        }
        return result;
    }
};
//TC - O(n)