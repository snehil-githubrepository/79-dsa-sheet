class Solution {
    public :
        vector<int> findMissingAndRepeatingNumbers(vector<int> a) {
            long long n = a.size();
            long long Sn = ( n * (n+1) )/ 2;
            long long S2n = ( n * (n+1) * (2n+1) )/ 6;
            long long S = 0 , S2 = 0;
            for(int i = 0; i < n ; i++) {
                S += a[i];
                S2 += (long long) a[i] * (long long) a[i];
            }
            long long val1 = S - Sn; // X-Y
            long long val2 = S2 - S2n;

            val2 = val2 / val1; // X + Y

            long long x  =(val1 + val2) / 2;
            long long y = x - val1;

            return {(int) x, (int) y};
        }
};

