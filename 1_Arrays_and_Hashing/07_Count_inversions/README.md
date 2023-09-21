# Count_inversion : Problem Statement

### _Given an array of N integers, count the inversion of the array (using merge-sort). What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i]._

_Example 1: <br>
Input Format: N = 5, array[] = {1,2,3,4,5} <br>
Result: 0_

_Example 2:<br>
Input Format: N = 5, array[] = {5,4,3,2,1}<br>
Result: 10_

_Example 3:<br>
Input Format: N = 5, array[] = {5,3,2,1,4} <br>
Result: 7_

---

#### 1. Brute Force

```cpp
cnt = 0
for(i = 0-> n) {
    for(j = i+1 -> n) {
        if(a[i] > a[j] ) cnt++;
    }
}
```

> TC : O(N^2) <br>
> SC : O(1)

---

#### 2. Optimal solution

- either we look for N log N or O(N)

Maybe we can break this array into 2 sorted arrays then the time complexity => O(N1+N2)

- we need to implement MERGE sort concept here , and in between when implementing them we need to figure out that there are pairs that follow
- left > right and add to the count var
- and before the last merging of array we will probably get all of our answers

- eg. [2, 3, 5] [1, 4] <= let's say this is the last 2nd step before mergin
- 2 -> low , 5 -> mid , 1 -> mid + 1 and 4 as high
- Now initial left = 2 and initial right = 1

- check for the condition , If right < left take all the numbers count in array 1 count after left .
- count += 3
- and keep checking this

