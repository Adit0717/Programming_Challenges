class Solution {
public:    
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0, row = grid.size(), column = grid[0].size(), freshCount = 0, rottenCount = 0;
        vector<vector<int>> visited(row, vector<int>(column, 0));
        queue<pair<pair<int, int>, int>> nodes;
        vector<int> rowValues = {-1, 0, 1, 0};
        vector<int> colValues = {0, 1, 0, -1};

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                if(grid[i][j] == 2) {
                    visited[i][j] = 2;
                    nodes.push({{i, j}, 0});
                }
                if(grid[i][j] == 1) {
                    freshCount ++;
                }
            }
        } // O(m * n)

        while(!nodes.empty()) {
            int ro = nodes.front().first.first;
            int col = nodes.front().first.second;
            int t = nodes.front().second;
            nodes.pop();
            time = max(time, t);

            for(int del = 0; del < rowValues.size(); del++) {
                int delRow = ro + rowValues[del];
                int delCol = col + colValues[del];

                if(delRow >= 0 && delRow < row && delCol >= 0 && delCol < column &&
                   grid[delRow][delCol] == 1 && visited[delRow][delCol] == 0) {
                    visited[delRow][delCol] = 2;
                    nodes.push({{delRow, delCol}, t + 1});
                    rottenCount++;
                }
            }
        } // what if all grids except 1st are placed with fresh oranges - O(m * n)
        if(rottenCount != freshCount) return -1;

        return time;
    }
};
/*       {r-1, c}   
{r, c-1} {r,c} {r, c+1}
         {r+1, c}


queue : {0,0,0} || {0,1,1} {1,0,1} || {0,1,2} {1,1,2} || {}
time?
*/
/*
//TC - O(m * n)
//SC - O(m * n)

         {r-1, c}
{r, c-1}  {r,c}   {r, c+1}
         {r+1, c}

queue : (0,0,0) || (0,1,1) (1,0,1) || (1,1,2) (0,3,2) || (2,1,3) || (2,2,4)
queue<pair<pair<int, int>, int>> nodes;
((x, y) time)
time = 1 + prevTime;
nodes.push({{x, y}, time});
*/