class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> result(mat.size(), vector<int>(mat[0].size(), 0));
        vector<vector<int>> visited(mat.size(), vector<int>(mat[0].size(), 0));
        queue<pair<pair<int, int>, int>> nodes;

        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[0].size(); j++) {
                if(mat[i][j] == 0) {
                    nodes.push({{i, j}, 0});                    
                    visited[i][j] = 1;
                }
            }
        }

        while(!nodes.empty()) {
            int row = nodes.front().first.first;
            int col = nodes.front().first.second;
            int len = nodes.front().second;

            result[row][col] = len;

            nodes.pop();

            vector<int> dRow = {-1, 1, 0, 0};
            vector<int> dCol = {0, 0, 1, -1};

            for(int i = 0; i < dRow.size(); i++) {
                int newRow = dRow[i] + row;
                int newCol = dCol[i] + col;

                if(newRow >= 0 && newRow < mat.size() && newCol >= 0 && newCol < mat[0].size()) {
                    if(visited[newRow][newCol] == 0) {
                        nodes.push({{newRow, newCol}, len + 1});
                        visited[newRow][newCol] = 1;                                             
                    }
                }
            }
        }

        return result;
    }
};