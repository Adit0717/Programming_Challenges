class Solution {
public:
    bool checkValue(vector<vector<char>>& board, char k, int i, int j) {
        for(int n = 0; n < 9; n++) {
            //column check
            if(board[n][j] == k) return false;
            //row check
            if(board[i][n] == k) return false;
            //box check - tricky
            if(board[3 * (i / 3) + n / 3][3 * (j / 3) + n % 3] == k) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == '.') {
                    for(char k = '1'; k <= '9'; k++) {
                        if(checkValue(board, k, i, j)) {
                            board[i][j] = k;
                            if(solve(board) == true) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }      
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
//TC - O(9^k) k - number of missing digits
//SC - At max it can be O(81) ~ O(1)