class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {        
        vector<int> track;        

        for(int i = 0; i < s1.size(); i++) {                                    
            if(s1[i] != s2[i])
                track.push_back(i);            
        }

        if(track.size() == 0)
            return true;
        if(track.size() != 2)
            return false;
        
        int i = track[0], j = track[1];

        return (s1[i] == s2[j] && s1[j] == s2[i]);
    }
};

//Runtime - 0ms
//Memory - 8.57mb