class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> visited(isWater.size(), vector<int>(isWater[0].size(), 0));
        vector<vector<int>> result = isWater;
        queue<pair<pair<int, int>, int>> nodes;

        for(int i = 0; i < isWater.size(); i++) {
            for(int j = 0; j < isWater[0].size(); j++) {
                if(isWater[i][j] == 1) {
                    nodes.push({{i, j}, 0});
                    visited[i][j] = 1;
                    result[i][j] = 0;
                }
            }
        }

        while(!nodes.empty()) {
            int r = nodes.front().first.first;
            int c = nodes.front().first.second;
            int val = nodes.front().second;

            result[r][c] = val;

            nodes.pop();

            vector<int> dRow = {-1, 1, 0, 0};
            vector<int> dCol = {0, 0, 1, -1};

            for(int i = 0; i < dRow.size(); i++) {
                int newRow = r + dRow[i];
                int newCol = c + dCol[i];

                if(newRow >= 0 && newRow < isWater.size() && newCol >= 0 && newCol < isWater[0].size()) {
                    if(visited[newRow][newCol] == 0 && isWater[newRow][newCol] == 0) {
                        nodes.push({{newRow, newCol}, 1 + val});
                        visited[newRow][newCol] = 1;
                    }
                }
            }
        }

        return result;
    }
};

/*
0 0 1
1 0 0
0 0 0

0 1 0
0 0 1
0 0 0

1 1 0
0 1 1
1 0 0

1 1 0
0 1 1
1 2 2
*/