class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k, l;

        for(k  = n-2; k  >= 0; k--) {
            if(nums[k] < nums[k+1]) {
                break;
            }
        }
        if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());

            // Test cases for this 
            
            //Example 1

            // Input: nums = [1,2,3]
            // Output: [1,3,2]

            // Example 2:

            // Input: nums = [3,2,1]
            // Output: [1,2,3]

            // Example 3:

            // Input: nums = [1,1,5]
            // Output: [1,5,1]
        }
    }
};