# include <bits/stdc++.h>

using namespace std;

bool dfs(vector<int> &result, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &pathVisited, int index) {
	visited[index] = 1;
	pathVisited[index] = 1;

	for(int &ele : adjList[i]) {
		if(visited[ele] == 0) {
			if(dfs(result, adjList, visited, pathVisited, ele) == true)
				return true;
		} else {
			if(pathVisited[ele] == 1) return true;
		}
	}

	pathVisited[i] = 0;
}

int main () {
	vector<vector<int>> adjList = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
	vector<int> result;
	vector<int> visited(adjList.size(), 0);
	vector<int> pathVisited(adjList.size(), 0);
	bool val = true;

	for(int i = 0; i < visited.size(); i++) {
		if(visited[i] == 0) {
			if(dfs(result, adjList, visited, pathVisited, i) == true) val = true;
			else val = false;
		}
	}	

	for(auto &ele : result) {
		cout << ele << " ";
	}

	return 0;
}