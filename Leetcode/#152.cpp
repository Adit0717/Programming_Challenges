class Solution {
	int maxProduct(vector<int> nums) {
	int maxProduct = INT_MIN;	
	
	for(int i = 0; i < nums.size(); i++) {
	for(int j = i; j < nums.size(); j++ ) {
		int product = 1;
	for(int k = i; k <= j; k++) {
		product = product * nums[k];
}
maxProduct = max(maxProduct, product);
}
}	
	return maxProduct;
}
};
//TC - O(n^3)
//SC - O(1)
class Solution {
	int maxProduct(vector<int> nums) {
	int maxProduct = INT_MIN, suffix = 1, prefix = 1;
	
	for(int i = 0; i < nums.size(); i++) {
	if(prefix == 0) prefix = 1;
	if(suffix == 0) suffix = 1;
	
	prefix = prefix * nums[i];
	suffix = suffix * nums[nums.size() - 1 - i];

	maxProduct = max(maxProduct, max(prefix, suffix));
}
return maxProduct;
}
};
//TC - O(n)
//SC - O(1)
