 //Shortest path algo using topological sort

# include <bits/stdc++.h>

using namespace std;

void toposortBFS(vector<vector<pair<int, int>>> &adjList, vector<int> &nodes, int n) {
	queue<int> track;
	vector<int> inDegree(n, 0);

	for(int i = 0; i < n; i++) {
		for(auto &ele : adjList[i]) {
			inDegree[ele.first]++;
		}
	}

	for(int i = 0; i < n; i++) {
		if(inDegree[i] == 0) track.push(i);
	}

	while(!track.empty()) {
		int node = track.front();
		track.pop();
		nodes.push_back(node);

			for(auto ele : adjList[node]) {
				inDegree[ele.first]--;
				if(inDegree[ele.first] == 0) track.push(ele.first);
			
		}
	}
}

void toposortDFS(vector<vector<pair<int, int>>> &adjList, vector<int> &visited, int index, stack<int> &st) {
	visited[index] = 1;

	for(pair<int, int> &ele : adjList[index]) {
		if(!visited[ele.first]) toposortDFS(adjList, visited, ele.first, st);
}
st.push(index);
}

int main() {
	int n = 7;
vector<vector<int>> edges = {{6, 5, 3}, {6, 4, 2}, {5, 4, 1}, 
  {4, 0, 3}, {4, 2, 1}, {0, 1, 2}, 
  {2, 3, 3}, {1, 3, 1}};	

	vector<vector<pair<int, int>>> adjList(n);
	vector<int> result(n, 1e9);
result[n - 1] = 0;

		for(vector<int> &x : edges) {
			int u = x[0];
			int v = x[1];
			int w = x[2];

			adjList[u].push_back({v, w});
		}
	
	stack<int> st;
	vector<int> nodes;
	
			// toposortDFS(adjList, visited, i, st);
			toposortBFS(adjList, nodes, n);



	for(int &node : nodes) {
		for(pair<int, int> &ele : adjList[node]) {
	int v = ele.first;
	int w = ele.second;

	if(result[node] + w < result[v]) {
		result[v] = result[node] + w;
		}
	}
	}
	/* for dfs
	while(!st.empty()) {
		int index = st.top();
		st.pop();
		for(pair<int, int> &ele : adjList[index]) {
	int v = ele.first;
	int w = ele.second;

	if(result[index] + w < result[v]) {
		result[v] = result[index] + w;
		}
}
}
*/

for(int ele : result) {
		cout << ele << " ";
}
	
	return 0;
}


