class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int start = -1, end = -1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(start == -1 && nums[i] == target) {
                start = i;                                
            }
            if(nums[i] == target) {
                end = i;
            }
        }
        if(start != -1 && end != -1) {
            result[0] = start;
            result[1] = end;
        }      
        
        return result;
    }
};
//[1] target = 1 => [0, -1] or [-1, -1] or [0, 0]
//TC - O(n) ; SC - O(1) - excluding auxilliray space

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r)/2;
            if(nums[mid] == target) {
                int start = mid, end = mid;
                while(start > 0 && nums[start] == nums[start - 1]) {
                    start--;
                }
                while(end < nums.size() - 1 && nums[end] == nums[end + 1]) {
                    end++;
                }
                result[0] = start;
                result[1] = end;
                return result;
            } else if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
/* TC - O(n) = In the worst case all elements are the same so 
               its o(n)
   SC - O(1)
*/


class Solution {
public:
    int searchFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, pos = -1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] == target) {
                pos = mid;
                r = mid - 1;
            } else if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }

    int searchLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, pos = -1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] == target) {
                pos = mid;
                l = mid + 1;
            } else if(nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return pos;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int l = 0, r = nums.size() - 1;
        int first = searchFirst(nums, target);
        if(first == -1) return result;
        int last = searchLast(nums, target);
        result[0] = first;
        result[1] = last;
        return result;
    }
};

//TC - 2 * O(logn)
//SC - O(1)