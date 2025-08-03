class Solution {
public:
    void solve(int n, int open, int close, vector<string>& result, string temp) {
        if(open == n && close == n) {
            result.push_back(temp);            
            return;
        } //base case

        if(open < n) {
            temp += '(';
            solve(n, open + 1, close, result, temp);
            temp.pop_back();
        } 
        if(close < open){
            temp += ')';
            solve(n, open, close + 1, result, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string temp;
        solve(n, 0, 0, result, temp);
        return result;
    }
};