class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() > 1 && nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums.size() > 1 && nums[nums.size() - 1] != nums[nums.size() - 2]) {
            return nums[nums.size() - 1];
        }

        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] != nums[i + 1] && nums[i] != nums[i - 1]) {
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
//TC - O(n)
//SC - O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() > 1 && nums[0] != nums[1]) {
            return nums[0];
        }
        if(nums.size() > 1 && nums[nums.size() - 1] != nums[nums.size() - 2]) {
            return nums[nums.size() - 1];
        }

        int l = 1, r = nums.size() - 2, mid = 0;

        while(l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }

            if((mid % 2) == 0) {
                if(nums[mid] == nums[mid + 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                 if(nums[mid] == nums[mid + 1]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }   
            } 
        }
        return result;
    }
};
//TC - O(logn)
//SC - O(1)

//1,1,2,3,3,4,4