class Solution {
public:
    string reorganizeString(string s) {
        string result(s.size(), ' ');
        vector<int> freq(26, 0);
        int maxFreq = 0; 
        char letter;

        for(char c : s) {
            freq[c - 'a']++;
            if(maxFreq < freq[c - 'a']) {
                maxFreq = freq[c - 'a'];
                letter = c;
            }
        }

        if(maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        int index = 0;
        while(freq[letter - 'a'] > 0) {            
            result[index] = letter;
            index += 2;
            freq[letter - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            while(freq[i] > 0) {
                if(index >= s.size()) index = 1;
                result[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }
        return result;
    }
};
/*
TC - O(len of string(n) + len/2 + 1) = O(n)
SC - O(1)
aaaabcde = abacadae
a-0; b-0; c-1; d-1
result = '';
"abacada"

"bfrbs"

Another way would be to use MaxHeap {count, char}
Pop top 2 characters -> form the result
Reduce the frequency and push it back into the Heap
*/

