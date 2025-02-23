class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN, i = 0, j = height.size() - 1;
        
        while(i < j) {
            maxArea = max(min(height[i], height[j]) * (j - i), maxArea);
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};

//TC - O(n)
//SC - O(1)