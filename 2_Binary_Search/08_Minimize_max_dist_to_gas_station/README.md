# Problem Statement : <br> Minimise Maximum Distance between Gas Stations

**Medium**

---

## _You are given a sorted array `‘arr’ of length ‘n’`, which contains positive integer positions of ‘n’ gas stations on the X-axis.<br> You are also given an `integer ‘k’`. You have to place ‘k’ new gas stations on the `X-axis`. <br> You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions`. Let ‘dist’ be the maximum value of the distance between adjacent gas stations `after adding k new gas stations. <br>Find the `minimum value` of ‘dist’. <br> Note: Answers within `10^-6 of the actual answer will be accepted`. For example, if the actual answer is `0.65421678124`, it is okay to return `0.654216`. Our answer will be accepted if that is the same as the actual answer up to the 6th decimal place._

```cpp
Example 1:
Input Format: N = 5, arr[] = {1,2,3,4,5}, k = 4
Result: 0.5
Explanation: One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this.
```

```cpp
Example 2:
Input Format: N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result: 1
Explanation: One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this.
```

---
