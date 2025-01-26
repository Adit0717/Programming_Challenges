class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN;
        int buy = prices[0];

        for(int i = 1; i < prices.size(); i++) {            
            maxProfit = max(maxProfit, (prices[i] - buy));
            buy = min(buy, prices[i]);
        }

        return maxProfit = (maxProfit < 0) ? 0 : maxProfit;
    }
};

// Runtime - 0ms 
// Memory - 97.27mb