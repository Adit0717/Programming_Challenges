class Solution {
public:
    int findPivotIndex(vector<int> &nums, int start, int end) {
        int pivotElement = nums[start];
        int i = start, j = end;

        while(i <= j) {
            while(i <= end && nums[i] <= pivotElement) {
                i++;
            }
            while(j >= start && nums[j] > pivotElement) {
                j--;
            }
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[start], nums[j]);
        return j;
    }

    int quickSelect(vector<int> &nums, int start, int end, int index) {
        if(start == end) return nums[start];
        int pivotIndex = findPivotIndex(nums, start, end);
        if(pivotIndex == index) {
            return nums[pivotIndex];
        } else if(pivotIndex < index) {
            return quickSelect(nums, pivotIndex + 1, end, index);
        } else {
            return quickSelect(nums, start, pivotIndex - 1, index);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        /*
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int x : nums) {
            minHeap.push(x);
            if(minHeap.size() > k) {
                minHeap.pop();
            } //nlogk + (n - k)logk
        }
        return minHeap.top();
        */        
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};
//1. nlogn
//2. nlogk
//3. n