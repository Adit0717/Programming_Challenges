class Solution {
public:
    int trapBruteForce(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        for (int i = 0; i < n; i++) {
            int maxLeft = 0, maxRight = 0;

            // Scan left of i
            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, height[j]);
            }

            // Scan right of i
            for (int j = i; j < n; j++) {
                maxRight = max(maxRight, height[j]);
            }

            int waterAtI = min(maxLeft, maxRight) - height[i];
            totalWater += waterAtI;
        }
        return result;        
    }

    int trap(vector<int>& height) {
        int count = 0;
        vector<int> prefixMax(height.size(), 0);
        vector<int> suffixMax(height.size(), 0);

        prefixMax[0] = height[0];
        for(int i = 1; i < height.size(); i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }
        
        suffixMax[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }

        for(int i = 0; i < height.size(); i++) {
            int leftMax = prefixMax[i], rightMax = suffixMax[i];
            if(height[i] < leftMax && height[i] < rightMax) {
                count += min(leftMax, rightMax) - height[i];
            }
        }
        return count;
    }

};

/*
How to calculate amount of water stored in those buildings?
total = Summation from 1-n : min(leftBld, rightBld) - current_building_height arr[i]
under the condition that the height of both leftBld and rightBld are greater than arr[i]
because water gets stored in between the buldings.
So the key to sovle this problem lies in identifying the heights of left and right buildings 
which are greater than arr[i].
Brute force approach would involve determining the heights of the buildings
in the "middle-out" fashion.
From arr[i], at most we have to compare n - 1 buildings to find out the heights of both the
buildings. So, this would be a n^2 approach.
*/