class Solution {
public:
    void bfs_solveAtlantic(int num_r, int num_c, unordered_map<string, pair<int, int>> &mp_a, vector<vector<int>> &visited, vector<vector<int>> &heights) {
        int col = num_c - 1;
        queue<pair<int, int>> nodes;
        
        for(int i = 0; i < num_r; i++) {
            visited[i][col] = 1;
            string temp = to_string(i) + "_i" + to_string(col) + "_j";
            nodes.push({i, col});
            mp_a[temp] = {i, col};
        }

        int row = num_r - 1;
        for(int i = 0; i < num_c - 1; i++) {
            visited[row][i] = 1;
            string temp = to_string(row) + "_i" + to_string(i) + "_j";
            nodes.push({row, i});
            mp_a[temp] = {row, i};
        }

        while(!nodes.empty()) {
            int ref_r = nodes.front().first;
            int ref_c = nodes.front().second;
            int val = heights[ref_r][ref_c];

            nodes.pop();
            vector<int> dRow = {-1, 1, 0, 0};
            vector<int> dCol = {0, 0, -1, 1};

            for(int i = 0; i < dRow.size(); i++) {
                int newRow = ref_r + dRow[i];
                int newCol = ref_c + dCol[i];

                if(newRow >= 0 && newRow < num_r && newCol >= 0 && newCol < num_c) {
                    if(visited[newRow][newCol] == 0 && heights[newRow][newCol] >= val) {
                        visited[newRow][newCol] = 1;
                        string temp = to_string(newRow) + "_i" + to_string(newCol) + "_j";
                        nodes.push({newRow, newCol});
                        mp_a[temp] = {newRow, newCol};
                    }
                }                
            }
        }
    }

    void bfs_solvePacific(int num_r, int num_c, unordered_map<string, pair<int, int>> &mp_p, vector<vector<int>> &visited, vector<vector<int>> &heights) {
        
        visited.assign(num_r, vector<int>(num_c, 0));
        int row = 0;
        queue<pair<int, int>> nodes;

        for(int i = num_c - 1; i >= 0; i--) {
            visited[row][i] = 1;
            string temp = to_string(row) + "_i" + to_string(i) + "_j";
            nodes.push({row, i});
            mp_p[temp] = {row, i};
        }
        
        int col = 0;
        for(int i = 1; i < num_r; i++) {
            visited[i][col] = 1;
            string temp = to_string(i) + "_i" + to_string(col) + "_j";
            nodes.push({i, col});
            mp_p[temp] = {i, col};
        }        

        while(!nodes.empty()) {
            int ref_r = nodes.front().first;
            int ref_c = nodes.front().second;
            int val = heights[ref_r][ref_c];

            nodes.pop();
            vector<int> dRow = {-1, 1, 0, 0};
            vector<int> dCol = {0, 0, -1, 1};

            for(int i = 0; i < dRow.size(); i++) {
                int newRow = ref_r + dRow[i];
                int newCol = ref_c + dCol[i];

                if(newRow >= 0 && newRow < num_r && newCol >= 0 && newCol < num_c) {
                    if(visited[newRow][newCol] == 0 && heights[newRow][newCol] >= val) {
                        visited[newRow][newCol] = 1;
                        string temp = to_string(newRow) + "_i" + to_string(newCol) + "_j";
                        nodes.push({newRow, newCol});
                        mp_p[temp] = {newRow, newCol};
                    }
                }                
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int num_r = heights.size(), num_c = heights[0].size();
        vector<vector<int>> result;
        unordered_map<string, pair<int, int>> mp_a;
        unordered_map<string, pair<int, int>> mp_p;
        vector<vector<int>> visited(num_r, vector<int>(num_c, 0));

        bfs_solveAtlantic(num_r, num_c, mp_a, visited, heights);
        bfs_solvePacific(num_r, num_c, mp_p, visited, heights);

        for(auto &ele : mp_a) {
            if(mp_p.find(ele.first) != mp_p.end()) {
                result.push_back({ele.second.first, ele.second.second});
            }
        }

        return result;
    }
};