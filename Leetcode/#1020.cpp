class Solution {
public:
    vector<int> dRow = {-1, 1, 0, 0};
    vector<int> dCol = {0, 0, 1, -1};

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j, vector<pair<int, int>> &input) {
        visited[i][j] = 1;
        input.push_back({i, j});

        for(int k = 0; k < dRow.size(); k++) {
            int r = i + dRow[k];
            int c = j + dCol[k];

            if(r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
                if(visited[r][c] == 0 && grid[r][c] == 1) dfs(grid, visited, r, c, input);                
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    vector<pair<int, int>> input;
                    dfs(grid, visited, i, j, input);

                    bool isConnectedToBorder = false;

                    for(auto &ele : input) {
                        int row = ele.first;
                        int col = ele.second;

                        if(row == 0 || row == grid.size() - 1 || col == 0 || col == grid[0].size() - 1) {
                            isConnectedToBorder = true;
                            break;
                        }
                    }

                    if(!isConnectedToBorder) {
                        result += input.size();
                    }
                }
            }
        }
        return result;
    }
};