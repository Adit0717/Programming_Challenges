class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int> &visited, int i) {
        visited[i] = 1;

        for(int j = 0; j < isConnected.size(); j++) {
            if(isConnected[i][j] == 1 && visited[j] == 0 && i != j) {
                dfs(isConnected, visited, j);
            }
        }        
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        vector<int> visited(isConnected.size(), 0);

        for(int i = 0; i < visited.size(); i++) {    
            if(visited[i] == 0) {
                dfs(isConnected, visited, i);
                result++;
            }            
        }
        
        return result;
    }
};
/*
1 1 0
1 1 0
0 0 1
*/