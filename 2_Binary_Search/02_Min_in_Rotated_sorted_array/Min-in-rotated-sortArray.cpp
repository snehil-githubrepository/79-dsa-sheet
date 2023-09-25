class Solution {
    public :
        //TC : O(Log N) : Average , if duplicates i.e. worst case => O(N)
        //SC : O(1)
        int findMin(vector<int>& arr) {
            int low = 0, high = arr.size() - 1;
            int ans = INT_MAX;

            while (low <= high) {
                    int mid = (low + high) / 2;
                    //search space is already sorted
                    //then arr[low] will always be
                    //the minimum in that search space:
                    //This is the optimization Bit:
                    if (arr[low] <= arr[high]) { //other half has this condition then its for sure the low as min
                        ans = min(ans, arr[low]);
                        break;
                    }

                    //if left part is sorted:
                    if (arr[low] <= arr[mid]) {
                        // keep the minimum:
                        //low is always answer  [ | 4, 5, 6, 7 |,  1 , 2, 3]
                        ans = min(ans, arr[low]);
                        // Eliminate left half:
                        low = mid + 1;
                    }

                    else { //if right part is sorted:

                        // keep the minimum:
                        ans = min(ans, arr[mid]);

                        // Eliminate right half:
                        high = mid - 1;
                    }
            }

            return ans;
        };
}