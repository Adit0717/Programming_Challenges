class Solution {
public:
    int calculate(string s) {
        int result = 0;
        stack<int> track;
        int currNum = 0;
        char op = '+';

        for(int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if(isdigit(curr)) {
                currNum = currNum * 10 + (curr - '0');
            }

            if(!isdigit(curr) && curr != ' ' || i == s.size() - 1) {
                if(op == '+') {
                    track.push(currNum);
                } else if(op == '-') {
                    track.push(-currNum);
                } else if(op == '*') {
                    int top = track.top();
                    track.pop();
                    track.push(top * currNum);
                } else {
                    int top = track.top();
                    track.pop();
                    track.push(top / currNum);
                }
                currNum = 0;
                op = curr;
            }            
        }

        while(!track.empty()) {
            result += track.top();
            track.pop();
        }
        return result;
    }
};