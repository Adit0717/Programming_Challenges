class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& result, 
        int target, vector<int>& temp, set<vector<int>> &tempSet) {

        if(target == 0) {
            if(tempSet.find(temp) == tempSet.end()) {
                tempSet.insert(temp);
                result.push_back(temp);
            }            
            return;
        }

        if(index >= candidates.size() || target < 0) {
            return;
        }        
        
        temp.push_back(candidates[index]);
        solve(index + 1, candidates, result, target - candidates[index], temp);

        temp.pop_back();
        solve(index + 1, candidates, result, target, temp);
    }

    vector<vector<int>> combinationSum2Brute(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        set<vector<int>> tempSet;
        solve(0, candidates, result, target, temp, tempSet);
        return result;
    }

    void solve2(int index, int target, vector<int> &input, vector<vector<int>> &result, vector<int> &temp) {
        if(target == 0) {
            result.push_back(temp);
            return;
        }
        
        for(int i = index; i < input.size(); i++) {
            if(input[i - 1] == input[i] && i > index) continue;
            if(target < input[i]) break;
            temp.push_back(input[i]);
            solve2(index + 1, target - input[i], input, result, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve2(0, target, candidates, result, temp);
        return result;
    }
};
//TC - O(nlogn + 2^n + )
//SC - Stack space + result vector + temp vector = O(T + K*T + T) - O(K*T)

//TC - O(nlogn + 2^n)
//SC - O(k * K + n)