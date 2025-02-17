class Solution{
public:
	vector<int> topKFrequent(vector<int> input, int k){
		vector<int> result;
		unordered_map<int, int> frequency;
		priority_queue<pair<int, int>> maxHeap;

		for(int element : input) {
			frequency[element]++;
		} //O(n)

		for(auto pair : frequency) {
			maxHeap.push({pair.second, pair.first});
		} //O(nlogn)


		while(result.size() < k && !maxHeap.empty()) {
			pair<int, int> maxElement = maxHeap.top();
			result.push_back(maxElement.second);
			maxHeap.pop();
		} //O(klogn)

		return result;
	}
};

//O(nlogn)
//O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> frequency;
        int maxFrequency = 0, maxElement = INT_MIN;
        
        for(int x : nums) {
            frequency[x]++;            
        }

        for(auto y : frequency) {
            if(y.second > maxFrequency) {
                maxFrequency = y.second;
                maxElement = y.first;
            }
        }

        while(result.size() < k) {
            for(auto x : frequency) {
                if(x.second == maxFrequency) {
                    result.push_back(x.first);
                }                
            }
            maxFrequency--;
        }
        return result;
    }
};

//O(3n)
//O(n)
