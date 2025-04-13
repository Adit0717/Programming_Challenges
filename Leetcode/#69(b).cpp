class Solution {
	int findNthRoot(int number, int value) {
		for(int i = 1; i <= number; i++) {
			int check = pow(i, value);
			if(check == number) {
				return i;
			} else if(check > number) {
				break;
			}
		}
		return -1;
	}
	// define power function
	int findPower(int base, int power) {
		int answer = 1;
		for(int i = 1; i <= power; i++) {
			answer = answer * base;
		}
		return answer;
	}
	int findNthRoot(int number, int value) {
		for(int i = 1; i <= number; i++) {
			int check = findPower(i, value);
			if(check == number) {
				return i;
			} else if(check > number) {
				break;
			}
		}
		return -1;
	}
	//optimal
	long long int findPower(int base, int power) {
		long long int answer = 1;
		for(int i = 1; i <= power; i++) {
			answer = answer * base;
		}
		return answer;
	}
	int findNthRoot(int number, int value) {
		int l = 1, r = number;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			long long int answer = findPower(mid, value);
			long long int compare = static_cast<long long int>(number);
			if(answer == compare) {
				return mid;
			} else if(answer > compare) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return -1;
	}
};
//1. using Pow function - O(log value); Total - O(number * log value)
//2. defining power function - O(value); Total - O(number * value)
//3. using binary search and power function; Total - O(log number * value)