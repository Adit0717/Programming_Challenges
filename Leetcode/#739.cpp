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
    // TC - O(n^2)
    // SC - O(n)

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> st;

        for(int i = temperatures.size() - 1; i >= 0; i--) {
            int ref = temperatures[i];
            
            while(!st.empty() && ref >= temperatures[st.top()]) st.pop();

            if(!st.empty()) answer[i] = st.top() - i;
            st.push(i);
        }
        
        /*
        for(int i = 0; i < temperatures.size(); i++) {
            int ref = temperatures[i];
            for(int j = i + 1; j < temperatures.size(); j++) {
                if(temperatures[j] - ref > 0) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        */
        
        return answer;
    }
    // TC - O()
    // SC - O()
};