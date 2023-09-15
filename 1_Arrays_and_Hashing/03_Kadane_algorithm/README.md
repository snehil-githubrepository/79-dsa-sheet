# Kadane's Algorithm (Maximum Subarray Sum in an Array) : Problem Statement

### _Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray._

===
_Example 1:<br>
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]<br>
Output: 6_

_Example 2:<br>
Input: nums = [1]<br>
Output: 1_

_Example 3:<br>
Input: nums = [5,4,-1,7,8]<br>
Output: 23_

---

1. _Brute force_

Since, its a subarray -> elements need to be contiguous

- We try out all the subarrays

```cpp
maxi = INT_MIN;
for(i = 0; i < n; i++) {
    for(j  = i ; j < n ;j++) {
        sum = 0;
        for(k = i ; k < j; k++) {
            sum += arr[k]
        }
        maxi = max(sum, maxi);
    }
}
```

> Time complexity for this approach is : O(N ^ 3), and Space complexity : O(1)

---
