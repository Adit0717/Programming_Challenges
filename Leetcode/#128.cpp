class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int count = 1, maxCount = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
            if(i < nums.size() - 1 && nums[i + 1] == nums[i] + 1) {
                count++;                
            } else {
                count = 1;
            }            
            maxCount = max(maxCount, count);            
        }
        return maxCount;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums.size();
        }
        cout << nums.size();
        int count = 1, maxCount = 1;
        unordered_set<int> track(nums.begin(), nums.end());

        for(int current : track) {
            if(track.find(current - 1) == track.end()) {
                int num = current;
                while(track.find(num + 1) != track.end()) {
                    count++;               
                    num++;
                }
                maxCount = max(count, maxCount);
                count = 1;
            }            
        }
        return maxCount;
    }
};

//1,2,3,4,100,200
//0,1,1,2