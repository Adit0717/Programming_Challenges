class Solution {
public:
    void solve(string digits, vector<string> &result, unordered_map<char, vector<char>> &mp, string temp) {        
        if(temp.size() == digits.size()) {
            result.push_back(temp);
            return;
        }

        char digit = digits[temp.size()];
        for(char ch : mp[digit]) {
            temp.push_back(ch);
            solve(digits, result, mp, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        unordered_map<char, vector<char>> mp;
        string temp;

        if(digits.empty()) return result;

        mp['2'] = {'a', 'b', 'c'};
        mp['3'] = {'d', 'e', 'f'};
        mp['4'] = {'g', 'h', 'i'};
        mp['5'] = {'j', 'k', 'l'};
        mp['6'] = {'m', 'n', 'o'};
        mp['7'] = {'p', 'q', 'r', 's'};
        mp['8'] = {'t', 'u', 'v'};
        mp['9'] = {'w', 'x', 'y', 'z'};

        solve(digits, result, mp, temp);
        return result;
    }
};
//TC - O(4^n)
//SC - O(n + n * 4^n)