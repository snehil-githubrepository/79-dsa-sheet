class Solution {
    public : 
        int findPeak(vector<int> &arr,int n) {
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2] ) return n-1;

        int low = 1, high = n-2;
        while(low <= high) {
            int mid = (low + high)/2;
            if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
            //increasing curve
            else if(arr[mid] > arr[mid-1]) {
                //peak always on right
                low = mid+1;
            }
            //decreasing curve
            else if(arr[mid] > arr[mid+1]) {
                //peak always on left
                high = mid-1;
            }
            //if on the lowest point for multiple curves
            //either go on right or left, both side would have a peak
            else {
                low = mid+1;
                //we could either do high = mid-1 as well, we just chose low = mid+1
            }
        }
        return -1;
    }
};