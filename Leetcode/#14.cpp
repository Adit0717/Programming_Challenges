class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        
        sort(strs.begin(), strs.end());
        string start = strs[0], end = strs[strs.size() - 1];
        for(int i = 0; i < start.size(); i++) {
            if(start[i] == end[i]) {
                result += start[i];
            } else {
                break;
            }
        }

        return result;
    }
};

// Runtime: 0ms
// Memory: 12.10mb

/*
Sorting would introduce nlogn complexity. Other approach would be
to fix the prefix as strs[0] & compare from strs[1]..strs[n-1].
Have a counter; take the small value for counter on each iteration.
If at all counter value reaches 0 on any iteration, return "".
The time complexity for this approach is O(n * m)
n -> number of strings
m -> length of the shortest string
*/