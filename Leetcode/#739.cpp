class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        
        for(int i = 0; i < temperatures.size(); i++) {
            int ref = temperatures[i];
            for(int j = i + 1; j < temperatures.size(); j++) {
                if(temperatures[j] - ref > 0) {
                    answer[i] = j - i;
                    break;
                }
            }
        }      
        return answer;
    }
};
// TC - O(n^2)
// SC - O(n)