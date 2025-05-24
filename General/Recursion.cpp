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

int main() {	
	//printName("aditya", 5);
	//print1ToN(5);
	//printNto1(1, 5);
	//int sum = sumofNNumbers(4);
	//int prod = factorial(5);	
	//reverseArray(nums, 0);
	//int sum = fibonaaci2(9);
	vector<int> nums = {1,2,1};
	subsequenceSumK(nums, 2);
}

//OS last chat
