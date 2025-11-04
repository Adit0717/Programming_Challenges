class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {        
        stack<int> st;

        for(int i = 0; i < asteroids.size(); i++) {
            int ref = asteroids[i];

            if(ref > 0) {
                st.push(ref);                
            } else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(ref)) st.pop();

                if(!st.empty() && st.top() == abs(ref)) st.pop();
                else if(st.empty() || st.top() < 0) st.push(ref);
            }
        }

        vector<int> result(st.size(), 0);
        int index = st.size() - 1;

        while(!st.empty()) {
            result[index] = st.top();
            st.pop();
            index--;
        }

        return result;
    }
};
//TC - O(3n) ~ O(n)
//SC - O(2n) ~ O(n)