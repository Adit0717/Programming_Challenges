class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        vector<int> result;
        int productLeft = 1, productRight = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                productLeft *= nums[i - 1];                
            } else {
                productLeft = 1;
            }
            result.push_back(productLeft);
        }

        for(int i = nums.size() - 1; i >= 0; i--) {
            if(i < nums.size() - 1) {
                productRight *= nums[i + 1];                
            } else {
                productRight = 1;
            }
            result[i] = (result[i] * productRight);
        }

        return result;
    }
};

//Runtime - 0ms 
//Memory - 41.5mb

/*
[1,2,3,4]

L : [1, 1, 2, 6]
R : [24, 12, 4, 1]
Result : [24, 12, 8, 6]

TC => O(3n)
SC => O(2n + n )

*/