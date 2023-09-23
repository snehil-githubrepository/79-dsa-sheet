# Count the number of subarrays with given xor K : Problem Statement

---

### _Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k._

```cpp
Example 1:
Input : arr[] = {4, 2, 2, 6, 4}, k = 6
Output : 4
```

```cpp
Example 2:
Input : arr[] = {5, 6, 7, 8, 9}, k = 5
Output : 2
```

---

#### 1. Brute Force

```cpp
for(i = 0-> n) {
    for(j = i -> n) {
        xor = 0
        for(k = i -> j) {
            xor = xor ^ arr[k];
        }
        if(xor == k) cnt++;
    }
}
```

> TC : O(N ^ 3) <br>
> SC : O(1)

---

#### 2. Better solution

Do we need the k loop -> the answer is no we can remove it.
<br>

as j is moving only the next element gets added to our xor, so it works something like this :

```cpp
for(i = 0-> n) {
    xr = 0
    for(j = i -> n) {
        xr = xr ^ arr[j];
        if(xr == k) cnt++;
    }
}
```

> TC : O(N^2) <br>
> Sc : O(1)

---

#### 3. Most Optimal Solution

- What we are looking for is : Is there a subarray ending at 6 & having a XOR of K.

[4, 2, 2, 6, 2, 1]

- if we take this entire from 4 to 6

we find the XR (xor) of this subarray and it consist of x {lets say 4} and K {2, 2, 6}

so , x ^ k = XR
-lets take k xor on both sides

- (x^k) ^ k = XR ^ k
- **X = XR ^ k**

- For this we need to see from the front and search for X
- We keep the track with using : **hashmap**

> (front Xor, cnt) ; Initial -> (0, 1)

---

Dry run :

input : [4, 2, 2, 6, 4] <br>

- Hashmap : {(0, 1) , (4, 1) , (6, 1) , (2,1) }

cnt => 4 (hashmap.size())
