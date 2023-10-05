# Problem Statement : Koko Eating Bananas

**`Medium`**

---

## _A monkey is given `‘n’ piles of bananas`, whereas the ‘ith’ pile has ‘a[i]’ bananas. An integer `‘h’` is also given, which `denotes the time (in hours)` for all the bananas to be eaten. <br> Each hour, the monkey chooses a `non-empty pile` of bananas and eats `‘k’ bananas`. If the pile contains `less than ‘k’ bananas`, then the monkey consumes all the bananas and won’t eat any more bananas in that hour. <br> Find the `minimum number of bananas ‘k’` to eat per hour so that the monkey can `eat all the bananas within ‘h’ hours`._

```cpp
Example 1:
Input Format: N = 4, a[] = {7, 15, 6, 3}, h = 8
Result: 5
Explanation: If Koko eats 5 bananas/hr, he will take 2, 3, 2, and 1 hour to eat the piles accordingly. So, he will take 8 hours to complete all the piles.
```

```cpp
Example 2:
Input Format: N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
Result: 25
Explanation: If Koko eats 25 bananas/hr, he will take 1, 1, 1, 1, and 1 hour to eat the piles accordingly. So, he will take 5 hours to complete all the piles.
```

---

#### 1. Brute Force

```cpp
fun(arr, hourly) {
    totalHours = 0;
    for (i = 0 -> n-1) {
        totalHours += ceil(arr[i]/hourly);
    }
    return totalHours;
}

for(i = 1-> max(arr)) {
    reqTime = fun(arr, i); // this is what u eat per hour "i"
    if(reqTime <= h) { //h is given deadline
         return;
    }
}
```

> TC : O(max(arr) x N) => This will give a TLE
> SC : O(1)

---

#### 2. Binary Search on Answers

- We need to be sure what the range is for this. The range should be min as that would determine the time complexity of binary search.

### DRY RUN

```
arr[3, 6, 7, 11] , h = 8
-------------------------------------

1  2  3  4  5  6  7  8  9  10  11
lo             |                hi
              mid

we see that 6 is a possible answer: ans = 6

we will go towards left because taking more value of mid won't help we want the min value for our answer

1  2  3  4  5
lo    |     hi
     mid

-> Total = 1 + 2 + 3 + 4 = 10

hence, this is not possible because our h = 8

4   5
lo  hi
mid

=>mid = (4+5)/2 = 4

for 4:
    1 + 2 + 2 + 3 = 8

this works for us, We update ans = 4 {as we need min}

-------------------
Now, we have already taken the minimum and there's nothing on left that we can use hence this will be our answer

now in next step hi > lo the binary search ends

-----------------------

Some observation , Lo was always at a point from starting that could not be our ans and Hi will always be at a possible number.

so, if Lo was standing at impossible at last it will always stand at possible and vice versa.
return low;
```

```cpp
bs (arr, h) {
    low = 1, high  =max(arr.begin(), arr.end());
    ans = INT_MIN;
    while(low <= high) {
        mid = (low + high)/2;
        totHrs  = fun(arr, mid);
        if(totHrs <= h) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid+1;
        }
    }
}
```
