class Solution {
public:
    void bfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int r, int c) {
        visited[r][c] = 1;
        queue<pair<int, int>> nodes;
        nodes.push({r, c});
        vector<int> dRow = {-1, 0, 1, 0};
        vector<int> dCol = {0, 1, 0, -1};
        while(!nodes.empty()) {
            int nRow = nodes.front().first;
            int nCol = nodes.front().second;
            nodes.pop();

            for(int i = 0; i < dRow.size(); i++) {
                int newrow = nRow + dRow[i];
                int newcol = nCol + dCol[i];

                if(newrow >= 0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size() &&
                visited[newrow][newcol] == 0 && grid[newrow][newcol] == '1') {
                    nodes.push({newrow, newcol});
                    visited[newrow][newcol] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {        
        int row = grid.size(), col = grid[0].size(), count = 0;
        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {                    
                    count++;                   
                    bfs(grid, visited, i, j);                    
                }
            }
        }
        return count;
    }
};
//TC - O(m * n) --visiting all grid cells
//SC - O(m * n) - queue ; dRow and dCol - constant vectors ; Visited matrix - O(m * n)