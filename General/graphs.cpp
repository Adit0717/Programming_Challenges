# include <bits/stdc++.h>
using namespace std;

void cycleDetection() {
	vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 5}, {3, 4}, {3, 6}, {5, 7}, {6, 7}};

	vector<vector<int>> adjList(edges.size() + 1);

	for(auto ele : edges) {
		adjList[ele[0]].push_back(ele[1]);
		adjList[ele[1]].push_back(ele[0]);
	}

	/*
	for(int i = 0; i < adjList.size(); i++) {		
		cout << i << " -> {";
		
		for(int j = 0; j < adjList[i].size(); j++) {
		 	string str = ", ";
		 	if(j == adjList[i].size() - 1) str = "";
		 	cout << adjList[i][j] << str;
		}
		
		cout << "}" << endl;		
	}
	*/

	vector<int> visited(edges.size() + 1, 0);
	queue<pair<int, int>> nodes;
	nodes.push({-1, 1});
	visited[1] = 1;

	while(!nodes.empty()) {
		int prev = nodes.front().first, curr = nodes.front().second;
		nodes.pop();

		for(int i = 0; i < adjList[curr].size(); i++) {
			int ele = adjList[curr][i];
			if(ele != prev) {							
				if(visited[ele] == 0) {
					nodes.push({curr, ele});
					visited[ele] = 1;
				} else {
					cout << "Cycle exists";
					return;
				}
			}
		}
	}
	cout << "Cycle does not exist";
}

{{1, 2}, {1, 3}, {2, 5}, {3, 4}, {3, 6}, {5, 7}, {6, 7}};

1 - 2, 3
2 - 1, 5
3 - 1, 4
4 - 3
5 - 2, 7
6 - 3, 7
7 - 5, 6

int main() {

	int nodes = 5, edges = 6;
	//Undirected graph
	vector<vector<int>> list = {{5, 0}, {4, 0}, {4, 1}, 
								{5, 2}, {2, 3}, {3, 1}};

	/* Adjacency Matrix; Space - O(n ^ 2 nodes)
	vector<vector<int>> adjMatrix(nodes + 1, vector<int>(nodes + 1, 0));

	for(int i = 0; i < list.size(); i++) {		
		int row = list[i][0], col = list[i][1];

		adjMatrix[row][col] = 1;
		adjMatrix[col][row] = 1;		
	}

	for(int i = 0; i < adjMatrix.size(); i++) {
		for(int j = 0; j < adjMatrix[i].size(); j++) {
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	*/

	/* Adjacency List; Space - O(2 * Edges) 
	vector<vector<int>> adjList(nodes + 1);

	for(int i = 0; i < list.size(); i++) {
		int row = list[i][0], col = list[i][1];

		adjList[row].push_back(col);
		adjList[col].push_back(row);
	}

	for(int i = 0; i < adjList.size(); i++) {		
		cout << i << " -> {";
		
		for(int j = 0; j < adjList[i].size(); j++) {
		 	string str = ", ";
		 	if(j == adjList[i].size() - 1) str = "";
		 	cout << adjList[i][j] << str;
		}
		
		cout << "}" << endl;		
	}
	*/

	cycleDetection();

	return 0;
}