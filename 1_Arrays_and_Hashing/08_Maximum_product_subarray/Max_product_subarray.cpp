class Solution  {
    public : 
    //Tc : O(N)
    // SC : O(1)
    int maxProductSubArray(vector<int> &arr) {
        int maxi = INT_MIN;
        int pref = 1;
        int suff = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref = pref * arr[i];
            suff = suff * arr[n - i - 1];

            maxi = max(maxi, max(pref, suff) );
        }

        return maxi;
    };
}