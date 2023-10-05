# Problem Statement : Aggressive Cows

**`Medium`**

---

## _You are given an array ‘arr’ of size ‘n’ which denotes the position of stalls._

## _You are also given an integer ‘k’ which denotes the number of aggressive cows._

## _You are given the task of assigning stalls to ‘k’ cows such that the minimum distance between any two of them is the maximum possible. Find the maximum possible minimum distance._

```cpp
Example 1:
Input Format: N = 6, k = 4, arr[] = {0,3,4,7,10,9}
Result: 3
Explanation: The maximum possible minimum distance between any two cows will be 3 when 4 cows are placed at positions {0, 3, 7, 10}. Here the distances between cows are 3, 4, and 3 respectively. We cannot make the minimum distance greater than 3 in any ways.
```

```cpp
Example 2:
Input Format: N = 5, k = 2, arr[] = {4,2,1,3,6}
Result: 5
Explanation: The maximum possible minimum distance between any two cows will be 5 when 2 cows are placed at positions {1, 6}.
```

---

#### 1. Brute force

```
0     3     4      7     9      10   , cows = 4
c1    c2    c3     c4              => min dist btw any 2 cows = 1 {c2, c3}
c1          c2           c3     c4 => 1
c1          c2     c3           c4 => 3

maximize the min dist = 3 {ans}
```

- We should just compare consecutive stall distances will give us answer, after sorting.

- We can see for the range here , [1, (max-min)] between 2 cows at maximum

```cpp
sort (arr)

bool canWePlace(arr, dist, cows) {
    cntCows = 1, last = arr[0];
    for(i = 1 -> n-1) {
        if(arr[i] - last>= dist) {
            cntCows++;
            last= arr[i];
        }
    }

    if(cntcows >= cows) return true;
    else return true;

}

for(i = 1 ;  i <= max-min) {
    if(canWePlace(arr, i , cows) == true) {
        continue;
    }
    else {
        return i-1; //return previous value when it was possible
    }
}
```

> TC : O(max-min) x O(n) <= Quadratic solution
> SC : O(1)

---

### 2. Binary Search

- Here, Lo is at a possible point and Hi is at impossible point. so high is always going to be our answer

```cpp
fn(arr, cows) {
    sort(arr)
    low = 0, high = a[n-1]-a[0]
    while(low <= high) {
        mid = lo+hi/2
        if(canWePlace(arr, mid, cows) == true) {
            ans = mid;
            low = mid+1
        }
        else {
            high = mid-1;
        }
    }
    return high ; //or ans
}
```

TC: O(N Log N) + O(Log (a[n-1]-a[0])) x O(N)
Sc : O(1)
