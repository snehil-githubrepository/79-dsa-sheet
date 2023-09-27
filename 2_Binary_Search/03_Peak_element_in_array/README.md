# Problem Statement : Peak element in Array

**`Easy`**

---

## _Given an array of length N. Peak element is defined as the element greater than both of its neighbors. Formally, if ‘arr[i]’ is the peak element, ‘arr[i – 1]’ < ‘arr[i]’ and ‘arr[i + 1]’ < ‘arr[i]’. Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, return the index of any peak number._

## _Note: For the first element, the previous element should be considered as negative infinity as well as for the last element, the next element should be considered as negative infinity._

```cpp
Example 1:
Input Format: arr[] = {1,2,3,4,5,6,7,8,5,1}
Result: 7
Explanation: In this example, there is only 1 peak that is at index 7.
```

```cpp
Example 2:
Input Format: arr[] = {1,2,1,3,5,6,4}
Result: 1
Explanation: In this example, there are 2 peak numbers that are at indices 1 and 5. We can consider any of them.
```

```cpp
Example 3:
Input Format: arr[] = {1, 2, 3, 4, 5}
Result: 4
Explanation: In this example, there is only 1 peak that is at the index 4.
```

```cpp
Example 4:
Input Format: arr[] = {5, 4, 3, 2, 1}
Result: 0
Explanation: In this example, there is only 1 peak that is at the index 0.
```

---

#### 1. Brute Force

## arr[i-1] < arr[i] > arr[i+1]

```cpp
for(int i = 0-> n) {
    if ( (i == 0 || arr[i-1] < arr[i]) &&
         ( i == n-1 || arr[i] > arr[i+1] ) ) {
            return i;
         }
}
```

> Tc : O(N)
> SC : O(1)

---

#### 2. Better solution

: Binary Search

- Why Binary Search ? Becase we can see it has some parts of sorting tendency . Even though there is peak the elements before and after kind of follow sorting kind of tendency.

- Let's assume array only has 1 peak, then we think of multiple.
- if arr has only 1 element that will be our answer, return 0;
- We can think of 3 cases for peak here

`if low -----mid---- peak ---- high`
`if low --- peak ----mid ---- high`
`if low -----mid=peak ---- high`

- what if we check on mid the mid-1 and mid+1 element and then figure out if we need to move right or left

- Now, if we have 1st or last element as the peak
- Just put this condition if(arr[0] > arr[1] || arr[n-1] > arr[n-2]) return either of the 2 whichever is the peak

- Now, since we have manually added code for index 0 and n-1 we have to begin the binary search from 1 to n-2

## For single peak we could write this :

```cpp
    int f(arr,n) {
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2] ) return n-1;

        low = 1, high = n-2;
        while(low <= high) {
            mid = (low + high)/2;
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
        }
        return -1;
    }
```

## For Multiple peak we could write with a single change :

- Here we might have a case where we need to take care of the lowest point
  eg. [1, 5, 1, 2, 1]

- the middle 1 is the lowest point and we need to take care bc none of the if-else conditions would come true .

### Change in the Code :

```cpp
    int f(arr,n) {
        if(n == 1) return 0;
        if(arr[0] > arr[1]) return 0;
        if(arr[n-1] > arr[n-2] ) return n-1;

        low = 1, high = n-2;
        while(low <= high) {
            mid = (low + high)/2;
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
```
