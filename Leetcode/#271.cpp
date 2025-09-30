class Codec {
public:    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {        
        string encodedString = "";
        for(string &word : strs) {
            encodedString += to_string(word.size()) + "#" + word;
        }
        return encodedString;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.size()) {
            int j = i;

            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            j++;

            string word = s.substr(j, len);
            result.push_back(word);

            i = j + len;
        }
        
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));