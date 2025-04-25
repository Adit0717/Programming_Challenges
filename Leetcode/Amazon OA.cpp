//Amazon OA

query = {}
nums = {}

class Solution {
	vector<int> topKELementSum(vector<int> nums, vector<int> query){
	vector<int> result;
	
	sort(nums.begin(), nums.end());

	for(int x : query) {
		int sum = 0;
		for(int i = 0; i < x; i++) {
			sum += nums[nums.size() - 1 - i];
		}
	result.push_back(sum);
	}
	return result;
}
};
//TC - O(n^2 + nlogn)
//SC - O(1)

class Solution {
	vector<int> topKELementSum(vector<int> nums, vector<int> query){
	vector<int> result;
	priority_queue<int> maxHeap;

	for(int x : nums) {
		maxHeap.push(x);
	} //O(nlogn)

	for(int y : query) {
		vector<int> temp;
		int sum = 0, count = 0;
		
		while(count < y && !maxHeap.empty()) {
			temp.push_back(maxHeap.top());
			sum += maxHeap.top();
			maxHeap.pop();
			count++;
		} // O(ylogn)

		result.push_back(sum);

		for(int x : temp) {
			maxHeap.push(x);
		} // O(ylogn)
		temp.clear();
	} // q * (2nlogn)

	return result;
	}
};

//TC - O(nlogn + q * 2nlogn)
//SC - O(n)

class Solution {
	vector<int> topKELementSum(vector<int> nums, vector<int> query){
	vector<int> result;
	vector<int> prefixSum(nums.size(), 0);

	sort(nums.begin(), nums.end(), greater<int>());

	int sum = 0;
	for(int i = 0; i < nums.size(); i++) {
		if(i == 0) {
			prefixSum[0] = nums[0];
			continue;
		}
		prefixSum[i] = prefixSum[i - 1] + nums[i];
	}

	for(int x : query) {
		result.push_back(prefixSum[x - 1]);
	}
	return result;
	}
};
//TC - O(nlogn + n + q)
//SC - O(n)
