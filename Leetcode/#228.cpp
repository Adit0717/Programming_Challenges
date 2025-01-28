class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        
        for(int i = 0; i < nums.size(); i++) {
            int start = nums[i], end = start;
            while(i < nums.size() - 1 && end + 1 == nums[i + 1]){
                end = nums[i + 1];
                i++;
            }
            if(start == end) {
                result.push_back(to_string(start));
            } else {
                string element = to_string(start) + "->" + to_string(end);
                result.push_back(element);
            }
        }

        return result;
    }
};

//Runtime - 0ms
//Memory - 9.13mb