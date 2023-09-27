# Problem Statement : Minimum in Rotated Sorted Array

---

## _Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array._

<div style="background-color: rgb(50, 50, 50);">
```cpp
Example 1:
Input Format: arr = [4,5,6,7,0,1,2,3]
Result: 0
Explanation: Here, the element 0 is the minimum element in the array.
```
</div>

```cpp
Example 2:
Input Format: arr = [3,4,5,1,2]
Result: 1
Explanation: Here, the element 1 is the minimum element in the array.
```

---

#### 1. Brute Force

```
Straight Off Approach would be to do a linear Search and find minimum element in the array. Using min(mini, arr[i])
```

> TC : O(N) , SC : O(1)

---

#### 2. Optimal Approach

- **Using Binary Search**

- Identify the sorted half.
- We can least say is that rotating point will always have minimum element.
- The portion that is not sorted has the minimum element for sure.

> We can say the sorted part, may or may not have the answer, Take the min from sorted half and eliminate

## Dry Run

- pick up the minimum from sorted half and keep that in a Variable **ans** and move the pointer to other side of unsorted array. keep comparing the minimum's with the **ans** variable

```
arr = [7, 8, 1, 2, 3, 4, 5, 6]
       L        m           H
ans = INT_MAX
---
Update : ans = 2 from the sorted half {2, 3, 4, 5, 6}
update H = m-1
---
find new m

[7, 8, 1]
 L  m  H

 eliminate the sorted half and compare min with the ans
---
[1]
 H
 L
 m

pick the min and compare with ans => ans = min(ans , 1);

ans = 1

return ans;
```
