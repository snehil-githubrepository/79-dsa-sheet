class solution {
    public:
        //TC : O(Log n) <- average case
        //SC : O(1)

        bool SearchRotatedArray (vector<int> &arr, int target) {
           int low = 0, high = n-1;

            while(low <= high) {
                mid = (low + high)/2;
                if(arr[mid] == target) return mid;

                if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
                    low = low + 1;
                    high = high - 1;
                }

                //left sorted
                if(arr[low] <= arr[mid]) {
                    if(arr[low] <= target && target <= arr[mid]) {
                        high = mid-1;
                    }
                    else {
                        low = mid+1;
                    }
                }
                //right sorted
                else {
                    if(arr[mid] <= target && target <= arr[high]) {
                        low = mid+1;
                    }
                    else {
                        high = mid-1;
                    }
                }
            }
            return false;
        }
}