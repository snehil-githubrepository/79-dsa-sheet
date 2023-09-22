# Maximum Product Subarray : Problem Statement

#_Given an array that contains both negative and positive integers, find the maximum product subarray._

_Example 1:< br/>
Input: < br/>
Nums = [1,2,3,4,5,0]< br/>
Output:< br/>
120_

_Example 2:< br/>
Input:< br/>
Nums = [1,2,-3,0,-4,-5]< br/>
Output:< br/>
20_

---

#### 1. Brute force

- Easy -> Generate all the subarrays.

Psedo :

```cpp
maxi = INT_MIN;
for(i = 0-> n) {
    for(j = i -> n) {
        prod = 1
        for(k = i -> j) {
            prod = prod * arr[k]
        }
        maxi = max(maxi, prod);
    }
}
```

> TC : O(n^3) <br/>
> SC : O(1)

---

#### 2. Better approach

> Now we should be thinking of a O(N ^ 2) kind of solution for the next step

- remove the k loop
- we keep multiplying one , one element at a time.

```cpp
maxi = INT_MIN;
for(i = 0-> n) {
    prod  =1;
    for(j = i -> n) {
        prod = prod * arr[j];
        maxi = max(maxi, prod);
    }
}
```

> TC : O(n^2) <br/>
> SC : O(1)

---

### 3. Optimal Approach

> Now we can think of O(N) Or O(N log n) solution

> 2 WAys to solve it optimally : **observation based <- tell this for the interviews**
> Way 2 is : using modification of kadane's algorithm <- never tell this in interview and its not intuitive

---

#### Observation Based approach

- 1. If array has all the positive elements , we can multiply everyone to get max product
- 2. If array has even number of negative elements even then we can product everyone to get max product subarray.
- 3. If odd negatives and all other are positives, [3, 2, -1, 4, -6, 3, -2 , 6] <== 3 negatives, if we mutiply everyone this product will come out to be negative. So what should we do? we should remove 1 negative element so that we are left with even number of negative elements and then we can find the max product.
- Whatever we take its either prefix subarray or suffix subarray
- we need to start from first and get all the prefix max and we need to start from last and get all the suffix max
- 4.  If it has zeros in subarray , eg. [-2, 3, 4, -1, 0, -2, 3, 1, 4, 0 , 4, 6, -1, 4], <br/> if we take Zeroes in subarray no matter how much big the number would have been the zero would make product as zero. In this case : <br/>
      > [-2, 3, 4, -1] this is seperate subarray
      > -2, 3, 1, 4 this is seperate subarray<br/>
      > 4, 6, -1, 4 this is another seperate subarray <br/>
           and we find max from all these subarrays.

> TC : O(N) <br/>
> SC : O(1)

---

[2, 3, -2, 4]

- max = INT_MIN
  pref = 1 => pref = 2 => better than maxi so => maxi = 2
  > On 3
- pref = 2 x 3 = 6
- maxi = 6
  > On -2
- pref = 6 x -2 = -12
- maxi = 6
  > On 4
- pref = -12 x 4
- maxi = 6

> Hence, 6 was the max and that was stored

> next step

[2, 3, -2, 4]

> On 4

- suff = 1 x 4 = 4
- maxi = 6

> on -2

- suff = 4 x -2 = -8
- maxi = 6

> ON 3

- suff = -8 x 3= -24
- maxi = 6

> On 2

- suff = -24 x 2 = -48
  -maxi = 6

> => 6 max was the answer

---

When we see that pref = 0 while mutiplying we turn it back to 1
and same for the suffix

---
