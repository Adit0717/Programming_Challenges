class Solution {
public:
    int dfs(int start, int end, vector<vector<int>> &visited, vector<vector<int>> &grid) {            
        visited[start][end] = 1;
        int area = 1;
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};

        for(int i = 0; i < dRow.size(); i++) {
            int row = start + dRow[i];
            int col = end + dCol[i];

            if(row >= 0 && row < grid.size() && col < grid[0].size() && col >= 0) {
                if(grid[row][col] == 1 && visited[row][col] != 1) {
                    visited[row][col] = 1;                    
                    area += dfs(row, col, visited, grid);
                }
            }
        }
        return area;
    }

    int bfs(int start, int end, vector<vector<int>> &visited, vector<vector<int>> &grid) {
        visited[start][end] = 1;
        int area = 1;
        queue<pair<int, int>> nodes;
        nodes.push({start, end});

        while(!nodes.empty()) {
            int refR = nodes.front().first, refC = nodes.front().second;            
            nodes.pop();

            vector<int> dRow = {-1, 1, 0, 0};
            vector<int> dCol = {0, 0, -1, 1};

            for(int i = 0; i < dRow.size(); i++) {
                int row = refR + dRow[i];
                int col = refC + dCol[i];

                if(row >= 0 && row < grid.size() && col < grid[0].size() && col >= 0) {
                    
                    if(grid[row][col] == 1 && visited[row][col] != 1) {
                        visited[row][col] = 1;
                        area++;
                        nodes.push({row, col});
                    }
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, area = 0;
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && visited[i][j] != 1) {
                    area = dfs(i, j, visited, grid);
                    // area = bfs(i, j, visited, grid);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};