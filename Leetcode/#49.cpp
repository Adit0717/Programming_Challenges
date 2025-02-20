class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> groups;

        for(string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            groups[sortedWord].push_back(word);
        }

        for(auto element : groups) {
            result.push_back(element.second);
        }

        return result;
    }
};

//TC - O(klogk * n)
// k - average length of a word and n - number of words
//SC - O(n*k)
//for the unordered map part 'n' - number of words & 
//'k' - size of the vector