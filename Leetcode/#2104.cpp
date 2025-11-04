class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {        
            int mini = INT_MAX, maxi = INT_MIN;
            for(int j = i; j < nums.size(); j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                sum += maxi - mini;
            }            
        }        
        return sum;
    }
    //TC - O(n^2)
    //SC - O(1)

    vector<int> pse(vector<int> &arr) {
        stack<int> st;
        vector<int> resL(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();

            if(!st.empty()) resL[i] = st.top();
            else resL[i] = -1;

            st.push(i);
        }

        return resL;
    }

    vector<int> nse(vector<int> &arr) {
        stack<int> st;
        vector<int> resR(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

            if(!st.empty()) resR[i] = st.top();
            else resR[i] = arr.size();

            st.push(i);
        }

        return resR;
    }

    vector<int> pge(vector<int> &arr) {
        stack<int> st;
        vector<int> resL(arr.size());

        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();

            if(!st.empty()) resL[i] = st.top();
            else resL[i] = -1;

            st.push(i);
        }

        return resL;
    }

    vector<int> nge(vector<int> &arr) {
        stack<int> st;
        vector<int> resR(arr.size());

        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();

            if(!st.empty()) resR[i] = st.top();
            else resR[i] = arr.size();

            st.push(i);
        }

        return resR;
    }

    // Very similar to #907
    long long subArrayRangesOPT(vector<int>& nums) {
        long long minSum = 0, maxSum = 0;

        vector<int> prevS = pse(nums);
        vector<int> nextS = nse(nums);
        vector<int> prevG = pge(nums);
        vector<int> nextG = nge(nums);

        // IDEA : sum of subarray max - sum of subarray min
        for(int i = 0; i < nums.size(); i++) {
            long long left = i - prevS[i];
            long long right = nextS[i] - i;

            long long left1 = i - prevG[i];
            long long right1 = nextG[i] - i;

            minSum = (minSum + (right * left) * 1LL * nums[i]); // sum of subarray min
            maxSum = (maxSum + (right1 * left1) * 1LL * nums[i]); // sum of subarray max
        }
        
        return maxSum - minSum;
    }
    //TC - O(n)
    //SC - O(n)
};
