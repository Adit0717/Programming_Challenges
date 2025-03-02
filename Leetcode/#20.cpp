class Solution {
public:
    bool isValid(string s) {
        stack<char> characters;

        for(char c : s) {
            if(characters.empty() || c == '(' || c == '[' || c == '{') {
                characters.push(c);
                continue;
            }
            char top = characters.top();
            if((c == ')' && top == '(') ||
               (c == ']' && top == '[') ||
               (c == '}' && top == '{')) {
                    characters.pop(); 
               } else {
                    return false;
               }
        }
        return characters.empty();
    }
};
//TC - O(n)
//SC - O(n)