class Solution {
public:
    void dfs(vector<int> &visited, vector<vector<int>> &adjList, int index) {
        visited[index] = 1;

        for(auto &ele : adjList[index]) {
            if(visited[ele] == -1) {
                visited[ele] = 1;
                dfs(visited, adjList, ele);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, -1);
        vector<vector<int>> adjList(n);
        int result = 0;

        for(int i = 0; i < edges.size(); i++) {
            int row = edges[i][0];
            int col = edges[i][1];

            adjList[row].push_back(col);
            adjList[col].push_back(row);
        }

        for(int i = 0; i < n; i++) {            
            if(visited[i] == -1) {
                result++;
                dfs(visited, adjList, i);
            }            
        }

        return result;
    }
};