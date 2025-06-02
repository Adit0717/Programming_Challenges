class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& nums, vector<int>& temp, int index) {
        result.push_back(temp);
        
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            solve(result, nums, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> temp;
        solve(result, nums, temp, 0);
        return result;
    }
};
//TC - O(2^n + 2^n*k*logK + K*k)
//SC - O(n + n + n * 2^n)