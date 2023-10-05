class Solution {
public:
    //TC : O(N * log(max_element(a[]) ),
    //SC : O(1) 
    int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
    }

    int calculateTotalHours(vector<int> &v, int hourly) {
        int totalH = 0;
        int n = v.size();
        //find total hours:
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHours(v, mid);
            if (totalH <= h) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};