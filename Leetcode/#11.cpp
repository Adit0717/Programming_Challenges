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

    int maxAreaBruteForce(vector<int>& height) {
        int maxArea = 0;
        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * (min(height[i], height[j]));
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};

//TC - O(n)
//SC - O(1)