# include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subArrayGen(vector<int> &input) {
	vector<vector<int>> result;

	for(int i = 0; i < input.size(); i++) {		
		for(int j = i; j < input.size(); j++) {
			vector<int> temp;
			for(int k = i; k <= j; k++) {
				temp.push_back(input[k]);
			}
			result.push_back(temp);	
		}		
	}

	return result;
}

int main() {
	vector<int> input = {3,1,2,4};
	vector<vector<int>> output = subArrayGen(input);
	int result = 0;

	for(vector<int> &row : output) {
		int mini = INT_MAX;
		for(int &x : row) {
			mini = min(mini, x);
			cout << x << " ";
		}
		cout << "- " << mini << endl;
		result += mini;
	}

	cout << "Minimum Sum: " << result;

	return 0;
}