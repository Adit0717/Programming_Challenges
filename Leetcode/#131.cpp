class Solution {
public:
    bool palindrome(int start, int end, string s) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }        
        return true;
    }

    void solve(vector<vector<string>>& result, int index, vector<string>& temp, string s) {
        if(index == s.size()) {
            result.push_back(temp);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(palindrome(index, i, s)) {
                temp.push_back(s.substr(index, i - index + 1));
                solve(result, i + 1, temp, s);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        solve(result, 0, temp, s);
        return result;
    }
};
//TC - O(n * 2^n)
//SC - O(n + n + k * n)