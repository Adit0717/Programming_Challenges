class Solution {
public:
    vector<int> dRow = {-1, 1, 0, 0};
    vector<int> dCol = {0, 0, 1, -1};

    void dfs(int r, int c, vector<vector<int>> &visited, vector<vector<char>> &board, vector<pair<int, int>> &input) {
        visited[r][c] = 1;        
        input.push_back({r, c});
        
        for(int i = 0; i < dRow.size(); i++) {
            int newRow = r + dRow[i];
            int newCol = c + dCol[i];

            if(newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size()) {
                if(visited[newRow][newCol] == 0 && board[newRow][newCol] == 'O') {
                    input.push_back({newRow, newCol});
                    dfs(newRow, newCol, visited, board, input);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == 'O' && visited[i][j] == 0) {
                    vector<pair<int, int>> input;
                    dfs(i, j, visited, board, input);

                    bool isConnectedToBorder = false;

                    for(auto &ele : input) {
                        int r = ele.first, c = ele.second;

                        if(r == 0 || r == board.size() - 1 || c == 0 || c == board[0].size() - 1) {
                            isConnectedToBorder = true;
                            break;
                        }
                    }

                    if(!isConnectedToBorder) {
                        for(auto &ele : input) {
                            board[ele.first][ele.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};