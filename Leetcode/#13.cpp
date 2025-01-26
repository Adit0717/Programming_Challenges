class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbols;

        symbols['I'] = 1;
        symbols['V'] = 5;
        symbols['X'] = 10;
        symbols['L'] = 50;
        symbols['C'] = 100;
        symbols['D'] = 500;
        symbols['M'] = 1000;

        int result = symbols[s[s.size() - 1]];

        for(int i = s.size() - 2; i >= 0; i--) {
            if(symbols[s[i]] < symbols[s[i + 1]]) {
                result -= symbols[s[i]];
            } else {
                result += symbols[s[i]];
            }            
        }

        return result;
    }
};

// Runtime - 5ms
// Memory - 12.38mb