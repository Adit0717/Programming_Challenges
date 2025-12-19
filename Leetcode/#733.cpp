class Solution {
public:
    void dfs(vector<vector<int>>& result, int i, int j, int color, vector<vector<int>>& visited, int initCol) {
        visited[i][j] = 1;
        result[i][j] = color;

        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};

        for(int k = 0; k < dRow.size(); k++) {
            int newRow = i + dRow[k];
            int newCol = j + dCol[k];

            if(newRow >= 0 && newRow < result.size() && newCol >= 0 && newCol < result[0].size()) {
                if(visited[newRow][newCol] == -1 && result[newRow][newCol] == initCol) {
                    result[newRow][newCol] = color;
                    visited[newRow][newCol] = 1;
                    dfs(result, newRow, newCol, color, visited, initCol);
                }
            }
        }
    }

    void bfs(vector<vector<int>>& result, int i, int j, int color, vector<vector<int>>& visited, int initCol) {
        visited[i][j] = 1;
        result[i][j] = color;

        queue<pair<int, int>> nodes;
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};

        nodes.push({i, j});

        while(!nodes.empty()) {
            pair<int, int> temp = nodes.front();
            nodes.pop();
            
            for(int k = 0; k < dRow.size(); k++) {
                int newRow = temp.first + dRow[k];
                int newCol = temp.second + dCol[k];

                if(newRow >= 0 && newRow < result.size() && newCol >= 0 && newCol < result[0].size()) {
                    if(visited[newRow][newCol] == -1 && result[newRow][newCol] == initCol) {
                        result[newRow][newCol] = color;
                        visited[newRow][newCol] = 1;
                        nodes.push({newRow, newCol});
                    }
                }
            }
        }        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> result = image;
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), -1));

        //dfs(result, sr, sc, color, visited, image[sr][sc]);
        bfs(result, sr, sc, color, visited, image[sr][sc]);

        return result;
    }
};