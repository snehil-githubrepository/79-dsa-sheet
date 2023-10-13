# Problem Statement : Median of 2 sorted arrays

**`Hard`**

---

## _Given two sorted arrays `arr1 and arr2` of size m and n respectively, return the `median of the two sorted arrays`.<br> The median is defined as the middle value of a sorted list of numbers. In case the length of the list is even, the `median is the average of the two middle elements`._

```cpp
Example 1:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result: 3.5
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.
```

```cpp
Example 2:
Input Format: n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result: 3
Explanation: The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.
```

---

#### 1. Brute Force

- let's have both the pointers standing on starting of both the arrays, then we create a new Big Array which will be arr1.len + arr2.len ;
- we keep increasing the pointer 1 by 1 and taking the lower value of both pointers and storing it in new Big Array .
- At last do first element + last element divide by 2 to get median

> This was 2 Pointer Approach , to get the answer

> TC : O(N1 + N2)
> SC : O(N1 + N2)

---

#### 2. Better Solution

- We can make SC to be O(1)
- Keeping all the steps the same way we only need element that are in middle to find median , so we just find that using a "cnt" variable and once done we can give the median => SC: O(1)

---

#### 3. Optimal Approach

> Obviously it will be Binary Search getting involved

- Since, the arrays are sorted this is the approach we should think of for efficiency.

- We can divide this question in two halves , how? well we know that sum of both array is lets say 10 -> so on the left half and the right half we have 5 and 5 elements .

- why don't we pick some elements from arr1 -> let's say 3 and some elements from arr2 -> let's say 2 => for the left half and similar on the right half

- or maybe we pick arr1 -> let's say 2 and arr2 -> 3 elements for the 5 elements and same on the right

- then check if we can make the left half combination which we would have got when we would've had full sorted big array, from those 5 elements on left and right.

### DRY RuN

```
arr1 = 1, 3, 4, 7, 10, 12
arr2 = 2, 3, 6, 15

sorted => 1 2 3 3 4 | 6 7 10 12 15

Now we can divide arr1 and arr2 in 2 parts , left and right

=>    1 3 4 7   |  10 12
            2   |  3  6  15

=>    1 3 4   | 7 10 12
        2 3   | 6  15

=>        1 3   | 4 7 10 12
        2 3 6   | 15

=>            1   | 3 4 7 10 12
        2 3 6 15  |

Now, we check if the picked left half is a valid one , i.e. it should be similar to the sorted left half

-> We just have to check this : if :

=>    {1 3 4 7}   |  (10 12)
            (2)   |  {3  6  15}

if {1 3 4 7} is smaller than {3 6 15} and (2) is smaller than (10 12), opposites on this thing

that means all the elements in 1 3 4 7 should be smaller than all the elements in {3 , 6 , 15}
check for all the cases

=>    1 3 4   | 7 10 12
        2 3   | 6  15

        let's say 4 is l1 and 3 as l2 and 7 as r1 and 6 is r2

we can say , max of left half => max(l1, l2)
min of right half => min(r1, r2)

max(l1, l2) + min(r1, r2) / 2 => this is my median

Validity check : l1 <= r2 and l2 <= r1

```

- we can now say that if there is a condition like 6 <= 4 for eg. we will have to move towards left and send 1 element to right half

#### DRY RuN

arr1 = 7, 12, 14, 15
partition -> 0 , 1, 2, 3, 4
arr2 = 1, 2, 3, 4, 9, 11

low = 0 and high = 4 (why ? because we take 5 elements for left and right half, and these are indexes)

- cut1 = 0 + 4 / 2 = 2

- 7 12 | 14 15

- cut2 = (5-cut1) = (5-2) = 3

- 1 2 3 | 4 9 11

let's figure out , l1 = 12 , 3 = l2 , r1= 14 , r2 = 4

we just check valid condition : If 12 <= 4 -> we see its not hence this is not valid partition
Now, we need to reduce 12 so we move towards left

so in binary search we do high = mid-1

- New high = 1

cut1 = 0 + 1 / 2 = 0
cut2 = (5-cut1) = (5-0) = 5

-           | 7 12 14 15
- 1 2 3 4 9 | 11

if we have no element as l1 => l1 = INT_MIN

l2 = 9 , r1 = 7, r2 = 11

check valid:

INT_MIN < 11
9 <= 7 -> this went wrong so even this is not our valid partition

we need to decrease 9 and increase 7
i.e. we take 7 from the right and put it to the left

new Low = mid + 1 => 1

cut1 = 1 + 1 / 2 =1
cut2 = (5-cut1) = (5-1) = 4

-       7 | 12 14 15
- 1 2 3 4 | 9 11

7 < 9 and 4 < 12 => this is valid one . yes!

> median = { max(7, 4) + min(12 + 9) }/ 2 = 8

we can say one thing from observation :

- l1 = arr1[cut1-1]
- l2 = arr2[cut2-1]
- r1 = arr1[cut1]
- r2 = arr2[cut2]

initialize it as INT_MIN at start for l1 and l2  
initialize it as INT_MAX at start for r1 and r2

---

- We did all these things for even length sum of arrays , in case if the arr was odd we do this instead, not a big change but :

=> (n1 + n2 + 1)/2 => we get the division of length

Over here we know that median will be last guy of our left half

Median => max(l1, l2)

---
