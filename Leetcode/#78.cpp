class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int index) {
        result.push_back(temp);
        
        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(result, nums, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(result, nums, temp, 0);
        return result;
    }
};
//TC - 2^n
//SC - n + n + k*2^n