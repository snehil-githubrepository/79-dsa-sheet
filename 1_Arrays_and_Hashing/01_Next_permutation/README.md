# Next_permutation : Problem Statement

---

### _Given an array Arr[] of integers, <br> rearrange the numbers of the given array into the lexicographically next greater permutation of numbers. <br> If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order)._

```cpp
Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]
```

```cpp
Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
```

```cpp
Example 3:
Output: [1,5,1]
```

---

#### 1. Brute force :

- 1. generate all the sorted permutations in dictionary order
- 2. linear search for the input given in quesiton
- 3. returning the next index and if the permutation is last one returning the first index
     <br>
     For eg. permutation of [1,2,3] : <br> { (1,2,3),(1,3,2), (2,1,3), (2,3,1), (3,1,2), (3,2,1) }

so we have almost N! permutations for an array and for swapping among those array length of N <br>

> Hence, the _Time complexity of brute force would be O (N! x N)_

---

_2. Using next permutation STL in c++_

```cpp
next_permutation(arr, arr+n);
```

---

_3. Most Optimal approach_

- _1. finding the longest prefix match and trying to find for the point / permutation that is right after the problem's input_

> eg. arr[] = [2, 1, 5, 4, 3, 0, 0] <br>

we start from the last index and keep looking for rearrangement such that the number which then generated would be next permutation....

- Also we need to find the next permutation and not the biggest permutation after the number

- 1. we need to find break point where the (i)th index is smaller than (i+1)th index , here it would be 1 < 5 hence index = 1 and index = 2 <br> after breakpoint we know that everything after breakpoint is bigger than the current index.

> [2, 1 - 5, 4, 3, 0, 0] : - represents breakpoint so i has 1 and i + 1 has 5 {condition is a[i] < a[i+1]>}

- 2. Now, we need to take such an element after breakpoint that is not smaller than the current index element (1) and is closer to the current index element i.e. either 2 , if not 3 , if not 4 , if not 5 ... if it does exist, so we will start loop from end and start checking for the required condition

> part 2 is : find some element > a[i] , but the smallest one on the right but also greater than a[i]

- 3. Try to place remaining elements now in sorted order for rest of the places

_[2, 3, 0, 0, 1, 4, 5]_

---

> Final algorithm: DRY RUN

```cpp
    ind = -1;
    for(i = n-2; i >= 0; i--) {
        if(a[i] < a[i+1] )
        {
            ind = 1; break;
        }
    }
```

_condition to check if permutation is last permutation_

```cpp
    if(ind == -1) {
        reverse(arr.begin(), arr.end());
    }
```

_now we need to find the element just greater than current element which is closer and just swap it_

```cpp
    //ind is the break point
    for(i = n-1 ; i >= ind; i-- ) {
        if(arr[i] > arr[ind] ) {
            swap(arr[i], arr[ind]);
            break;
        }
    }
```

_now we just need to reverse from the breakpoint + 1 index to the end_

```cpp
    rev(arr, ind+1, n-1);
    //from ind+1 till last index (n-1)
```
