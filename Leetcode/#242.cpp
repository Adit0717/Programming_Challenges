class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size() || s.empty() || t.empty())
	        return false;

        vector<int> alphabets(26, 0);

        for(char c : s) {
	        alphabets[c - 'a']++;
        }

        for(int i = 0; i < t.size(); i++) {
	        if(alphabets[t[i] - 'a'] <= 0){
		        return false;
            }
            alphabets[t[i] - 'a']--;
        }
        return true;
    }
};

//TC - O(n)
//SC - O(1)