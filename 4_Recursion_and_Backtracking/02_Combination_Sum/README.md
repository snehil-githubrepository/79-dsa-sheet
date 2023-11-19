## Problem Statement : Combination Sum – 1 [MEDIUM]

### _Given an array of **distinct** integers `candidates` and a target integer `target`, return a list of all **unique combinations** of `candidates` where the chosen numbers sum to `target`. You may return the combinations in **any order**. <br/>The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different. The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input._

```cpp
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
```

```cpp
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

```cpp
Example 3:

Input: candidates = [2], target = 1
Output: []
```

---

## Observation

> By this time we know that in recursion and in questions like these we use the concept of **pick** and **not-pick**

> Also we can pick the same index multiple times from the problem statement

### Approach-1

- arr[] = [2, 3, 6, 7]
- target = 7

we can start the function with

```cpp
                //index, target, vector/list
                     f (0, 7, nums)
                /                       \
         pick  /                         \ unpick
        f(0, 5, |2|)                    f(1, 7, | |)
            /      \                     /           \
           /        \                   /             \
   f(0, 3, |2, 2|)  f(1, 5, |2|)   f(1, 4, |3|)    f(2, 7, | |)
     /             \
f(0, 1, |2, 2, 2|) f(1, 3, |2, 2|)
    /
 //can't pick anymore

 //similary for everything else
```

- when index = n , and if target is 0 then data structure is part of combination we are looking for.

so our recursive function would look something like this :

```cpp
                        f(ind, target, ds)
                 /                                   \
       f(ind, target-a[ind], ds.add(a[ind]))    f(ind+1, target, ds)
    //in backtracking make sure to remove this element from ds[ind]
```

- make sure while picking => if(a[ind] <= target)
- if (ind == n) if (target==0) add this to data structure

> TC : (2 ^ t) x k {(2 ^ t) because we have 2 options on each index "pick/not-pick" and avg. len of every combination is k and we put this in ds}
> SC : k _ x , {k length _ x combinations} => we can't predict because how many combinations can be generated , dependent on no. of combinations 
