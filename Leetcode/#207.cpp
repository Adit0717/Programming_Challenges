class Solution {
public:
    int bfs(int numCourses, vector<vector<int>> &prerequisites) {
        int count = 0;
        vector<vector<int>> list(numCourses);

        for(auto ele : prerequisites) {
            list[ele[1]].push_back(ele[0]);
        }

        vector<int> inDegree(numCourses, 0);
        
        for(int i = 0; i < list.size(); i++) {
            for(auto ele : list[i]) {
                inDegree[ele]++;
            }
        }

        queue<int> nodes;
        for(int i = 0; i < inDegree.size(); i++) {
            if(inDegree[i] == 0) nodes.push(i);
        }

        while(!nodes.empty()) {
            int temp = nodes.front();
            nodes.pop();
            count++;

            for(auto ele : list[temp]) {
                inDegree[ele]--;
                if (inDegree[ele] == 0) {
                    nodes.push(ele);                
                }

            }
        }
        return count;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int nodes = bfs(numCourses, prerequisites);

        if(nodes != numCourses) return false;
        return true;
    }
};