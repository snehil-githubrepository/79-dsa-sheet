class Solution {
public:
    //TIME COMPLEXITY : O(n log n) + O(n x n) ~ O(n log n) + O(n ^ 2)
    //SPACE COMPLEXITY : O (number of unique triplets) , i.e. ans list that we are using to store answers

    vector<vector<int>> triplet(int n, vector<int> &arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end()); //N LOG N
        for(int i = 0;i < n; i++) { // N
            // if i is not first element , we check with previous value that the new a[i] should not have same value as prev a[i] value
            // if so we will continue to move forward
            if (i > 0 && arr[i] == arr[i-1]) continue;

            int j = i+1;
            int k = n-1;
            while( j < k) { // near about N 
                int sum = arr[i] + arr[j] + arr[k];
                if(sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    //when x = 0 condition
                    //this is my triplet
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //also we check while moving j and k that it should not have equal value to prev arr[j] and arr[k]
                    //so keep moving until it is equivalent to prev
                    while(j < k && arr[j] == arr[j-1]) j++;
                    while(j < k && arr[k] == arr[k+1]) k--;
                }
            }
        }
        return ans;      
    }
};