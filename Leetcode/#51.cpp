class Solution {
public:
    bool check(int row, int col, vector<string>& temp, int n) {
        int refCol = col;
        int refRow = row;

        //check upper diagonal
        while(col >= 0 && row >= 0) {
            if(temp[row][col] == 'Q') return false;
            col--; row--;
        }

        //check lower diagonal
        row = refRow; col = refCol;
        while(col >= 0 && row < n) {
            if(temp[row][col] == 'Q') return false;
            col--; row++;
        }

        //check previous columns
        row = refRow; col = refCol;
        while(col >= 0) {
            if(temp[row][col] == 'Q') return false;
            col--;
        }
        return true;
    }

    void solve(int n, vector<vector<string>>& result, vector<string>& temp, int col) {
        if(col == n) {
            result.push_back(temp);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(check(row, col, temp, n)) {
                temp[row][col] = 'Q';
                solve(n, result, temp, col + 1);
                temp[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> temp(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) {
            temp[i] = s;
        }

        solve(n, result, temp, 0);
        return result;
    }
};
//TC - O(n * n!) => n for check() and n! choices
//SC - O(k * n^2 + n + n^2)