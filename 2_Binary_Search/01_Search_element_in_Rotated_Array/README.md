# Problem Statement : Search Element in Rotated Sorted Array II

---

### Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

```
Example 1:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
Result: True
```

```
Example 2:
Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 10
Result: False
```

---

#### 1. Brute Force

```
simply go through a linear search and find the element and if it does not exist return False, and if it does return true
TC : O(N); SC :  O(1)
```

#### 2. Better WAy -> Binary Search

- Now, WE know binary search can actually make the array time complexity short of : O(Log N)

> Implementation

[3, 1, 2, 3, 3, 3, 3] , Target = 1;

Now, here index = 0 => low , index = 3 => mid , index = 6 => high

we can't compare with these pair of numbers to trim.. so what should we do ??

- Problem we have is => arr[low] = arr[mid] = arr[high]
- we need to solve this condition.
- we first search if this is the desired target and if its not we trim down the search space
- low ++ and high --

```cpp
f(arr, n, target) {
    low = 0, high = n-1;

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
```

> Tc : O(Log n)
> SC : O(1)

---

Tc worst case : [3, 3, 1, 3, 3, 3, 3] In this case we will keep shrinking until we get answer which will result in :

> O(N/2) = Worst CAse TC
