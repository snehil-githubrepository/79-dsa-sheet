class Solution {
public:
    //TIME COMPLEXITY ~ O(n) + O(n) + O(n) ~ O(3n)
    //SPACE COMPLEXITY = O(1)

    vector<int> nextPermutation(vector<int>& arr) {
        //the break point variable
        int ind=-1;

        int n = arr.size();
        //O(n)
        for(int i = n-2; i >= 0; i--) {
            if(arr[i] < arr[i+1]) {
                ind = i;
                break;
            }
        }

        //for last permutation
        if(ind == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        //step 2
        //O(n)
        for(int i = n-1; i > ind; i-- ) {
            if(arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        //last step
        //O(n)
        reverse(arr.begin() + ind + 1, arr.end());

        return arr;
    }
};