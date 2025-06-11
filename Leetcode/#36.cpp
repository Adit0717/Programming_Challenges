class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int column, char c) {
        for(int i = 0; i < 9; i++) {
            //Row check
            if(board[row][i] == c && i != column) return false;
            
            //Column check
            if(board[i][column] == c && i != row) return false;
        
            //Box check
            int boxRow = 3 * (row / 3) + (i / 3);
            int boxCol = 3 * (column / 3) + (i % 3);

            if (boxRow == row && boxCol == column) continue;
            if (board[boxRow][boxCol] == c) return false;
        }  
        return true;    
    }

    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') {
                    char ch = board[i][j];
                    if(isValid(board, i, j, ch) == false) {
                        return false;
                    }                        
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};
/*
(3,6) (3,7) (3,8)
(4,6) (4,7) (4,8)
(5,6) (5,7) (5,8)
*/
//TC - O(1)
//SC - O(1)