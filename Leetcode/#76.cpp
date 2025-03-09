class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size() < t.size())
            return "";
        
        int index = -1, length = INT_MAX, l = 0, r = 0, count = 0;
        vector<int> freq(256);

        for(int i = 0; i < t.size(); i++) {
            freq[t[i]]++;
        }

        while(r < s.size()) {
            if(freq[s[r]] > 0) {
                count++;
            }
            freq[s[r]]--;
            while(count == t.size()) {
                if(length > (r - l + 1)) {
                    length = (r - l + 1);
                    index = l;
                }
                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if(index == -1 && length == INT_MAX)
            return "";

        return s.substr(index, length);
    }
};