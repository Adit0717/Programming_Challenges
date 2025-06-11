#include <bits/stdc++.h>

void printName(string name, int n) {	
	if(n == 0) {
		return;
	}
	cout << name << " ";
	printName(name, n - 1);
}
//TC - O(n)
//SC - O(n)

void print1ToN(int n) {
	if(n == 0)
		return;
	//cout << n << " "; // For printing in reverse
	print1ToN(n - 1);
	cout << n << " "; // For printing in order
}
//TC - O(n)
//SC - O(n)

void printNto1(int i, int n) {
	if(i == n + 1)
		return;
	printNto1(i + 1, n);
	cout << i << " ";
}
//TC - O(n)
//SC - O(n)

int sumofNNumbers(int n) {
	if(n == 0) {
		return 0;
	}
	return sumofNNumbers(n - 1) + n;
}
//TC - O(n)
//SC - O(n)

int factorial(int n) {
	if(n <= 1)
		return 1;
	return n * factorial(n - 1);
}
//TC - O(n)
//SC - O(n)

void reverseArray(vector<int>& nums, int index) {
	if(index >= nums.size() / 2)		
		return;
	swap(nums[index], nums[nums.size() - 1 - index]);
	reverseArray(nums, index + 1);
}
//TC - O(n/2)
//SC - O(n/2)

int fibonaaci(int n) {
	if(n == 1)
		return 1;
	if(n == 0)
		return 0;
	return fibonaaci(n - 1) + fibonaaci(n - 2);
}
//TC - O(2^n)
//SC - O(n)

int fibonaaci2(int n) {
	int first = 0, second = 1;
	for(int i = 2; i <= n; i++) {
		int third = first + second;
		first = second;
		second = third;
	}
	return second;
}

bool flag = false;
void solveSumK(int index, vector<int> &nums, vector<int> &output, 
	int k, int sum) {	
	if(index >= nums.size()) {
		if(sum == k && flag == false) {
			for(int x : output) {
				cout << x << " ";
			}
			cout << endl;
			flag = true;
		}
		return;
	}	
	
	output.push_back(nums[index]);
	sum += nums[index];
	solveSumK(index + 1, nums, output, k, sum);

	output.pop_back();
	sum -= nums[index];
	solveSumK(index + 1, nums, output, k, sum);
}

void subsequenceSumK(vector<int> &nums, int k) {
	vector<int> output;
	int sum = 0;
	solveSumK(0, nums, output, k, sum);
}
//TC - O(2 ^ n)
//SC - O(n)

void powerSet(vector<int> &input, vector<int> &result, int sum, int index) {
	if(index == input.size()) {
		result.push_back(sum);
		return;
	}
	powerSet(input, result, sum + input[index], index + 1);
	powerSet(input, result, sum, index + 1);
}
//TC - O(2^n)
//SC - Stack space + result vector - O(n + 2^n)

void permutations(vector<int> &input, unordered_set<int> &track,
				  vector<vector<int>> &result, vector<int> &temp) {
	if(temp.size() == input.size()) {
		result.push_back(temp);
		return;
	}

	for(int i = 0; i < input.size(); i++) {
		if(track.find(i) == track.end()) {
			track.insert(i);
			temp.push_back(input[i]);
			permutations(input, track, result, temp);
			temp.pop_back();
			track.erase(i);
		}
	}
}
//TC - O(n! * n)
//SC - stack space + temp array + result + set
//SC - n + k + N * k + k => O(n!*n)

void permutations2() {
	
}

void ratInAMaze(vector<vector<int>>& input, int row, int col, int n, vector<string>& result, string& temp, vector<vector<bool>>& visited) {
	if(row < 0 || col < 0 || row >= n || col >= n || 
	   input[row][col] == 0 || visited[row][col]) return;
	
	if(row == n - 1 && col == n - 1) {
		result.push_back(temp);
		return;
	}
	
	visited[row][col] = true;
	
	vector<int> rows = {1, 0, 0, -1};
	vector<int> cols = {0, -1, 1, 0};
	string dir = "DLRU";

	for(int i = 0; i < 4; i++) {
		int dRow = row + rows[i];
		int dCol = col + cols[i];
		temp.push_back(dir[i]);
		ratInAMaze(input, dRow, dCol, n, result, temp, visited); //down	
		temp.pop_back();
	}

	visited[row][col] = false;
}
//Rat starts at (0,0) and needs to finish at (N-1, N-1)
//TC - O(4^(n^2))
//SC - O(n^2)

int main() {
	//printName("aditya", 5);
	//print1ToN(5);
	//printNto1(1, 5);
	//int sum = sumofNNumbers(4);
	//int prod = factorial(5);	
	//reverseArray(nums, 0);
	//int sum = fibonaaci2(9);
	//subsequenceSumK(nums, 2);
	//powerSet(input, result, 0, 0);
	//permutations(input, track, result, temp);
}

//OS last chat
