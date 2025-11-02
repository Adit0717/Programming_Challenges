/*
Find Missing Elements

You are given an integer array nums consisting of unique integers.
Originally, nums contained every integer within a certain range. However, some integers might have gone missing from the array.
The smallest and largest integers of the original range are still present in nums.
Return a sorted list of all the missing integers in this range. If no integers are missing, return an empty list.

Example 1:

Input: nums = [1,4,2,5]

Output: [3]

Explanation:
The smallest integer is 1 and the largest is 5, so the full range should be [1,2,3,4,5]. Among these, only 3 is missing.
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;

        sort(nums.begin(), nums.end());

        int j = 0, l = nums[0], r = nums[nums.size() - 1];
        for(int i = l; i <= r; i++) {            
            while(i != nums[j]) {
                result.push_back(i);
                i++;
            }
            j++;
        }
        
        return result;
    }
};

/*
Maximum Product of Three Elements After One Replacement
You are given an integer array nums.
You must replace exactly one element in the array with any integer value in the range [-10^5, 10^5] (inclusive).
After performing this single replacement, determine the maximum possible product of any three elements 
at distinct indices from the modified array.

Return an integer denoting the maximum product achievable.

Input: nums = [-5,7,0]
Output: 3500000
Explanation:
Replacing 0 with -10^5 gives the array [-5, 7, -10^5], 
which has a product (-5) * 7 * (-10^5) = 3500000. 
The maximum product is 3500000.
*/

class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        long long result = 0;
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        int temp = 2;
        long long prod = 1;
        
        while(temp > 0) {
            if(abs(nums[l]) >= abs(nums[r])) {
                prod *= nums[l];
                l++;
            } else {
                prod *= nums[r];
                r--;
            }
            temp--;
        }
        result = prod;
        cout << result;
        if(prod < 0) result = result * pow(-10, 5);
        else result = result * pow(10, 5);
        
        return result;
    }
};

/*
Minimum Time to Complete All Deliveries

You are given two integer arrays of size 2: d = [d1, d2] and r = [r1, r2].
Two delivery drones are tasked with completing a specific number of deliveries. Drone i must complete di deliveries.
Each delivery takes exactly one hour and only one drone can make a delivery at any given hour.
Additionally, both drones require recharging at specific intervals during which they cannot make deliveries. Drone i must recharge every ri hours (i.e. at hours that are multiples of ri).
Return an integer denoting the minimum total time (in hours) required to complete all deliveries.

Input: d = [3,1], r = [2,3]

Output: 5

Explanation:

The first drone delivers at hours 1, 3, 5 (recharges at hours 2, 4).
The second drone delivers at hour 2 (recharges at hour 3).
*/

class Solution {
public:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;        
        return (a / gcd(a, b)) * b;
    }

    bool canFinish(long long T, long long d1, long long d2, long long r1, long long r2) {
        
        long long common_lcm = lcm(r1, r2);
        long long slots_1_only = (T / r2) - (T / common_lcm);
        long long slots_2_only = (T / r1) - (T / common_lcm);
        
        long long slots_both = T - (T / r1) - (T / r2) + (T / common_lcm);

        if (d1 > slots_1_only + slots_both) {
            return false;
        }

        if (d2 > slots_2_only + slots_both) {
            return false;
        }

        if (d1 + d2 > slots_1_only + slots_2_only + slots_both) {
            return false;
        }

        return true;
    }
    
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long d1 = d[0], d2 = d[1];
        long long r1 = r[0], r2 = r[1];        
        long long low = d1 + d2; 
        long long high = 2e14; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canFinish(mid, d1, d2, r1, r2)) {
                ans = mid;
                high = mid - 1;
            } else {                
                low = mid + 1;
            }
        }
        return ans;
    }
};