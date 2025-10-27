# include <bits/stdc++.h>

using namespace std;

vector<int> nextSmallerElement(vector<int>& input) {
	vector<int> result(input.size(), 0);
	stack<int> st;

	for(int i = 0; i < input.size(); i++) {
		while(!st.empty() && input[i] <= st.top()) st.pop();

		if(st.empty()) {
			result[i] = -1;
		} else {
			result[i] = st.top();
		}
		st.push(input[i]);
	}

	return result;
}

int main() {
	vector<int> input = {4, 5, 2, 10, 8};
	vector<int> output = nextSmallerElement(input);

	for(int x : output) {
		cout << x << " ";
	}

	return 0;
}