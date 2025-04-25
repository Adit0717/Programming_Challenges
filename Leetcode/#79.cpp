class Solution {
public:
    bool searchNext(vector<vector<char>>& board, string word, int row, int col, int index) {
        if(index == word.size())
            return true;
        if(row < 0 || row >= board.size() ||
           col < 0 || col >= board[0].size() ||
           board[row][col] != word[index]) {
            return false;
        }
        char tmp = board[row][col];
        board[row][col] = '#';

        bool top = searchNext(board, word, row - 1, col, index + 1);
        bool bottom = searchNext(board, word, row + 1, col, index + 1);
        bool left = searchNext(board, word, row, col - 1, index + 1);
        bool right = searchNext(board, word, row, col + 1, index + 1);

        board[row][col] = tmp;

        return top || bottom || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int index = 0;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[index]) {
                    if(searchNext(board, word, i, j, index)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
//TC - O(m * n * 4 ^ l)
//SC - O(l)