class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int len = 0;
        
        for(int i = 0; i < s.size(); i++) {
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if((r - l + 1) > len) {
                    result = s.substr(l, r - l + 1);
                    len = (r - l) + 1;
                }
                l--; r++;
            }
        }

        for(int i = 0; i < s.size(); i++) {
            int l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if((r - l + 1) > len) {
                    result = s.substr(l, r - l + 1);
                    len = (r - l) + 1;
                }
                l--; r++;
            }
        }

        return result;
    }
};

//O(2 * n^2)