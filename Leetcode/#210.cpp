class Solution {
public:
    void bfs(int numCourses, vector<vector<int>> &prerequisites, vector<int> &result, vector<vector<int>> &list) {
        vector<int> indegrees(numCourses, 0);

        for(int i = 0; i < list.size(); i++) {
            for(auto ele : list[i]) {
                indegrees[ele]++;
            }
        }

        queue<int> nodes;
        for(int i = 0; i < indegrees.size(); i++) {
            if(indegrees[i] == 0) nodes.push(i);            
        }

        while(!nodes.empty()) {
            int temp = nodes.front();
            nodes.pop();
            result.push_back(temp);

            for(auto ele : list[temp]) {
                indegrees[ele]--;
                if(indegrees[ele] == 0) nodes.push(ele);
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> list(numCourses);

        for(vector<int> ele : prerequisites) {
            list[ele[1]].push_back(ele[0]);
        }

        bfs(numCourses, prerequisites, result, list);
        
        if(result.size() == numCourses) return result;

        return {};
    }
};