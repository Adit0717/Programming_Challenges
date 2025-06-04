class Solution {
public:
    void solve(int start, int k, int target, vector<vector<int>>& result, vector<int>& temp){        
        if(temp.size() == k && target == 0) {
            result.push_back(temp);
            return;
        }
        if(temp.size() >= k) {
            return;
        }

        for(int i = start; i < 10; i++) {            
            temp.push_back(i);
            solve(i + 1, k, target - i, result, temp);
            temp.pop_back();            
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;        
        solve(1, k, n, result, temp);
        return result;
    }
};
//k - number of digits; n - target
//TC - nCk => meaning that we would produce unique combinations
// and prune
//SC - O(k * n + k + k)