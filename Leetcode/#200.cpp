class Solution {
public:
    void dfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int i, int j) {
        visited[i][j] = 1;

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};

        for(int k = 0; k < dRow.size(); k++) {
            int newRow = i + dRow[k];
            int newCol = j + dCol[k];

            if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
                if(grid[newRow][newCol] == '1' && visited[newRow][newCol] == 0) {
                    visited[newRow][newCol] = 1;
                    dfs(visited, grid, newRow, newCol);
                }
            }
        }
    }

    void bfs(vector<vector<int>> &visited, vector<vector<char>> &grid, int i, int j) {
        visited[i][j] = 1;

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};
        queue<pair<int, int>> track;

        track.push({i, j});

        while(!track.empty()) {
            int tRow = track.front().first;
            int tCol = track.front().second;

            track.pop();

            for(int i = 0; i < dRow.size(); i++) {
                int newRow = dRow[i] + tRow;
                int newCol = dCol[i] + tCol;

                if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
                    if(visited[newRow][newCol] == 0 && grid[newRow][newCol] == '1') {
                        visited[newRow][newCol] = 1;
                        track.push({newRow, newCol});
                    }
                }                
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {        
        int result = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1' && visited[i][j] == 0) {
                    //dfs(visited, grid, i, j);
                    bfs(visited, grid, i, j);
                    result++;
                }
            }
        }        
        return result;
    }
};
//TC - O(m * n) --visiting all grid cells
//SC - O(m * n) - queue ; dRow and dCol - constant vectors ; Visited matrix - O(m * n)