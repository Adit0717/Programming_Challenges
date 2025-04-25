class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count = 0;
        unordered_set<string> track(wordList.begin(), wordList.end());
        queue<pair<string, int>> bfs;
        bfs.push({beginWord, 1});
        track.erase(beginWord);

        while(!bfs.empty()) {
            pair<string, int> instance = bfs.front();
            string rootWord = instance.first;
            int len = instance.second;
            bfs.pop();
            if(rootWord == endWord) {
                return len;
            }
            
            for(int i = 0; i < rootWord.size(); i++) {
                char original = rootWord[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    rootWord[i] = ch;
                    if(track.find(rootWord) != track.end()) {
                        bfs.push({rootWord, 1 + len});
                        track.erase(rootWord);                        
                    }
                }
                rootWord[i] = original;
            }
        }
        return 0;
    }
};
/*
hit =>
[a..z]it = 26 words - we would search this word in the set
h[a..z]t = 26 words - we would search this word in the set
hi[a..z] = 26 words - we would search this word in the set

if(found && wordFormed != rootWord){ 
    bfs.push({wordFormer, 1 + len});
    track.erase(wordFormed);
} else {
    continue;
}


"hot", "dot", "lot", "dog"
["log","cog"]

{hit,1}
|
{hot, 2} || {}
|
{dot, 3} || {lot, 3}
|               |
{dog, 4}     {log, 4}
|
{cog, 5}

return; no further traversal

//TC - O(26 * L * N) ; L - (AVG length of word) ; N - (number of words in WordList)
//SC - O(n * l) - set + O(n * l) - queue + O(n * l)
*/