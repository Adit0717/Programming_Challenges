class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string result = "";
        vector<int> numbers;
        
        for(int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k - 1;

        while(true) {
            result += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0) {                
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }

        return result;
    }
};
/*
f(3, 3) : answer - 213
Total permutations = 3! = 6
fixing one digit at a place., individual permutations = 2 + 2 + 2 = 6

0th - 5th permutation: 
123, 132 : (0, 1)
213, 231 : (2, 3)
312, 321 : (4, 5)

Initial:
[1,2,3]
k = 2
fact = 2
result = nums[2/2] = nums[1] = 2

13, 31 : (0, 1)
[1,3]
k = 0
fact = 1
result = nums[1] = 21

[3]
k = 0
fact = 1
result = 213
*/