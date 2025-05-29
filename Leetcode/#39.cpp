class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& result, int target, vector<int>& temp) {
        if(index >= candidates.size() || target < 0) {
            return;
        }

        if(target == 0) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[index]);
        solve(index, candidates, result, target - candidates[index], temp);

        temp.pop_back();
        solve(index + 1, candidates, result, target, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(0, candidates, result, target, temp);
        return result;
    }
};
//TC - O(2^T)
//SC - Stack space + result vector + temp vector = O(T + K*T + T) - O(K*T)