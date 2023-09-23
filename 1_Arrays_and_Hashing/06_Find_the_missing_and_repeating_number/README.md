# Find the Missing and Repeating Number : Problem Statement

---

### _You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing._

```
_Example 1:<br>
Input Format: array[] = {3,1,2,5,3}<br>
Result: {3,4}<br>
Explanation: A = 3 , B = 4 <br>
Since 3 is appearing twice and 4 is missing_ <br>
```

```
_Example 2:<br>
Input Format: array[] = {3,1,2,5,4,6,7,5}<br>
Result: {5,8)<br>
Explanation: A = 5 , B = 8<br>
Since 5 is appearing twice and 8 is missing_
```

---

#### 1. Brute Force

```cpp
repeating = -1 , missing = -1

for(i = 1; i < n) {
    cnt = 0;
    for(j = 0 -> n-1) {
        if(arr[j] == i) {
            cnt++;
        }
    }
    if (cnt == 2) repeating = i;
    else if (cnt == 0) missing = i;

    if(repeating != -1 && missing != -1 ) break;
}
```

> TC : O(N^2) <br>
> SC : O(1)

---

#### 2. Better approach

- Lets use hashmap

- WE can say for sure that all the numbers will be from 1->N;
- n = 0 to index 6
- hash arr => _ ,_ ,_ ,_, _, _, -,

-initialize all the indexes with 0 = > | 0 , 0 , 0, 0, 0, 0, 0 |

- iterate on the array and keep incrementing the count in hash Arr
- Once iteration is complete , start iterating from 1 to 6 in hash Arr and see for count.
- if count = 2 -> put this in repeating and if count = 0 -> put this in missing number

```cpp
    int hash[n+1] = 0;
    for(i = 0-> n) {
        hash[a[i]]++;
    }
    int repeating = -1, missing = -1;

    for(i = 1; i <= n) {
        if(hash[i] == 2) repeating = i;
        if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1) break;
    }

    return {repeating, missing};
```

> TC : O(2N) <br>
> SC : O(N)

---

### 3. Optimal Solution

---

#### Case 1 : Maths

- lets take x and y , x -> repeating and y -> missing
- we sum up all the elements of the array -> S
- also we sum up all the elements from 1 to n -> ( n x (n+1) ) / 2 => Sn
- We will now subtract them both = S - Sn
- Now, the thing is : X - Y = S - Sn <== **Equation 1**
- Now we need another equation to solve for X and Y

- Let's sum up the squares of array => S2
- summation of squares of first n natural numbers => S2n => ( n x (n+1) x (2n+1) ) /6
- we will find that : X^2 - Y^2 = S2 - S2n <== **Equation 2**
- (X - Y) (X + Y) = S2 - S2n
- put in (X-Y) from eq. 1
- We get Equation new as => (X+Y) = (S2 - S2n) / (X-Y) <== **Eq 3**
- we can now find X and Y from Eq 1 and Eq 3

```cpp
    long long Sn = ( n * (n+1) )/ 2
    long long S2n = ( n * (n+1) * (2n+1) )/ 6
    long long S = 0 , S2 = 0;
    for(int i = 0; i < n ; i++) {
        S += a[i];
        S2 += (long long) a[i] * (long long) a[i];
    }
    long long val1 = S - Sn; // X-Y
    long long val2 = S2 - S2n;

    val2 = val2 / val1; // X + Y

    long long x  =(val1 + val2) / 2;
    long long y = x - val1;

    return {(int) x, (int) y};

```

> TC : O(N) <br>
> SC : O(1)

---

#### Case 2 : XOR

> We can totally stop after giving the mathematical intuition approach and we don't have to give the XOR approach

- We will update on this later ....

---
