class Solution {
public:
    int lengthOfLongestSubstring(string s) {        
        if(s.size() == 0)
            return 0;

        int length = 0, l = 0, r = 0;
        unordered_set<char> letters;

        while(r < s.size()) {
           if(letters.find(s[r]) == letters.end()) {
                letters.insert(s[r]);
                length = max(length, (r - l + 1));
                r++;
           } else {
                letters.erase(s[l]);
                l++;
           }
        }
        return length;
    }
};
//TC - O(n)
//SC - O(n)