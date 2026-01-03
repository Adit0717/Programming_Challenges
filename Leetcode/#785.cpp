class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &visited, int index, int val) {
        visited[index] = val;

        for(int i : graph[index]) {
            if(visited[i] == 0) {
                if(dfs(graph, visited, i, -val) == false)
                    return false;
            } else if(visited[i] == visited[index]) {
                return false;
            }
        }
        return true;
    }

    bool bfs(vector<vector<int>> &graph, vector<int> &visited) {
        for(int i = 0; i < graph.size(); i++) {
            if(visited[i] == 0) {
                queue<int> nodes;
                nodes.push(i);

                visited[i] = 1;

                while(!nodes.empty()) {
                    int ref = nodes.front();
                    nodes.pop();

                    for(int x : graph[ref]) {
                        if(visited[x] == 0) {
                            visited[x] = -visited[ref];
                            nodes.push(x);
                        } else if(visited[x] == visited[ref]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {        
        vector<int> visited(graph.size(), 0);

        //bool answer = bfs(graph, visited);
        
        for(int i = 0; i < visited.size(); i++) {
            if(visited[i] == 0) {
                if(!dfs(graph, visited, i, 1)) return false;
            }            
        }
        
        return true;
    }
};