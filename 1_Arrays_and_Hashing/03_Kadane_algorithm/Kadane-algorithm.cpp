class Solution {
public:
    //TC : O(N)
    //SC : O(1)
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum > maxi) maxi = sum;

            if(sum < 0) {
                sum = 0;
            }
        }
        
        //if arr = [-4, -3, -2, -1] 
        //for this case we should return empty subarray []  
        // uncomment the following check:

        //if (maxi < 0) maxi = 0;

        return maxi;
    }
};