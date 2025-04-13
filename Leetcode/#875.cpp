class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = INT_MIN, result = 0;
        
        for(int i = 0; i < piles.size(); i++) {            
            maxRate = max(maxRate, piles[i]);
        } //O(n)

        for(int i = 1; i <= maxRate; i++) {
            int rate = 0;
            for(int num : piles) {                
                rate += ceil(num / (double)i);
                if(rate > h) {
                    break;
                }
            }        
            if(rate <= h) {
                result = i;
                break;
            }
        }
        return result;
    }
};

class Solution {
public:
    int totalHours(vector<int> &piles, int mid, int limit) {
        int rate = mid;
        int total = 0;
        for(int i = 0; i < piles.size(); i++) {                
            total += ceil(piles[i] / (double)rate);
            if(total > limit) {
                break;
            }
        } //O(n)
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxRate = INT_MIN, result = 0;
        
        for(int i = 0; i < piles.size(); i++) {            
            maxRate = max(maxRate, piles[i]);
        } //O(n)

        int l = 1, r = maxRate;
        while(l <= r) {
            int mid = l + (r - l) / 2;            
            int total = totalHours(piles, mid, h);
            if(total <= h) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } //O(logn)
        return l;
    }
};
//TC - O(n) + O(log(maxValue) * n)