# include <iostream>
using namespace std;

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

	/* Adjacency List; Space - O(2 * Edges) */
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

	return 0;
}

int solve(int index, vector<int>& heights, vector<int> &dp) {
	if(index <= 0) return 0;

	if(!dp[index] != -1) {
		return dp[index];
	}

	int ans = INT_MAX;
	for(int i = 1; i < k; i++) {
		if(k <= index) {
			int oneStep = solve(index - i, heights) + abs(heights[index] - heights[index - k]);	
		}		
		ans = min(ans, oneStep);
	}	

	return dp[index] = ans;
}

int frogJump(int n, vector<int>& heights) {
	vector<int> dp(n + 1, -1);
	int time = solve(n - 1, heights, dp);

	return time;
}