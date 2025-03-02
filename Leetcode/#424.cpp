class Solution {
public:
    int characterReplacement(string s, int k) {
        int length = 0, l = 0, r = 0;
        vector<int> freq(26, 0);

        while(r < s.size()) {
            freq[s[r] - 'A'] += 1;
            int maxFreq = *max_element(freq.begin(), freq.end());
            
            while( (r - l) + 1 - maxFreq > k) {
                freq[s[l] - 'A'] -= 1;
                l++;
            }
            length = max(length, (r - l) + 1);
            r++;
        } 
        return length;
    }
};
/*
window
maxElement & its frequency

AABABBA ; k = 1
window.size() = 4
r = 'A' @3
l = 'A' @0
maxElement = 'A' and its freq = 3

if (window.size() - freq <= k) {
    len = max(len, (r - l) + 1);
} else {
    l++;
}
*/