# Kadane's Algorithm (Maximum Subarray Sum in an Array) : Problem Statement

---

### _Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray._

```cpp
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
```

```cpp
Example 2:
Input: nums = [1]
Output: 1
```

```cpp
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
```

---

#### 1. Brute force

Since, its a subarray -> elements need to be contiguous

- We try out all the subarrays

```cpp
maxi = INT_MIN;
for(i = 0; i < n; i++) {
    for(j  = i ; j < n ;j++) {
        sum = 0;
        for(k = i ; k < j; k++) {
            sum += arr[k]
        }
        maxi = max(sum, maxi);
    }
}
```

> Time complexity : O(N ^ 3) <br>
> Space complexity : O(1)

---

#### 2. Better Solution

So first thing here is to optimize time complexity , let's try to get it to O(N^2) <br>

[-2,1,-3,4,-1,2,1,-5,4]<br>
for instance here we should try to eliminate the k loop , we can see one thing->
sum is always going in this manner : {-2} then {-2, 1} , then {-2, 1, -3}<br>

we do not have to sum it again and again for subarrays we just need to add the extra element to existing sum. and from that we will be able to eliminate k loop in brute force.<br>

_Updated Code_

```cpp
maxi = INT_MIN;
for(i = 0; i < n; i++) {
    sum = 0;
    for(j  = i ; j < n ;j++) {
        sum += arr[j];
        maxi = max(sum, maxi);
    }
}
```

> Time complexity : O(N ^ 2) <br>
> Space Complexity : O(1)

---

#### 3. Most Optimal Solution

_We need to make N ^ 2 complexity better, Now we will be using Kadane's Algorithm for this_

_let's initialize the maximum to be lowest number_

[-2, -3, 4, -1, -2, 1, 5, -3]<br>

- We start from the 0th index and initial sum = 0;
- When we go to -2 element , we update sum => -2
- Once that's done we compare **sum** and **maxi** and take maximum of them in **maxi** variable.
- maxi gets updated with -2

> new values are maxi = -2 and sum = -2

- But taking sum = -2 in next step won't be good enough , so when sum < 0 we don't take it forward with us because it will only make our sum smaller than before.
- So when sum < 0 => make sum = 0 : and then move forward
- Now -3 gets added to the sum and we compare it with maxi and since its smaller than maxi we update **sum = 0** and keep **maxi = -2**
- We then move to 4 in next iteration and update sum = 4 and compare with maxi and since **sum > maxi** we update **maxi = 4** and keep _sum = 4_ because _sum > 0_

> update values of maxi = 4 and sum = 4 till this point.

- Now we add -1 and the **sum = 3** , we compare it with maxi and since sum is still greater than 0 and not negative we should carry sum forward.
- We then move to -2 and update sum + (-2) = 1 , we compare with maxi and its not greater so we keep maxi and sum as it is and move forwards, we still carry sum forward.
- next we have 1 so we add it to sum => 2, we compare and we move forward as sum > 0
- we move forward and add 5 to sum => 7 , we compare with maxi and we not update maxi with 7 and since sum > 0 we move forward.
- next we have -3 and if we add sum with -3 it will become 4 , which won't be greater than maxi.

_At end of day our answer is maxi_

> Basically kadane algorithm states we simply move forward and keep on adding elements and if sum < 0 , we drop the sum.

_Code example_

```cpp
int sum = 0, maxi = INT_MIN;

for(int i = 0; i < nums.size(); i++) {
    sum += nums[i];

    if(sum > maxi) maxi = sum;

    if(sum < 0) {
        sum = 0;
    }
}

//But what if arr = [-4, -3, -2, -1]
//for this case we should return empty subarray []
// To consider the sum of the empty subarray
// uncomment the following check:

//if (maxi < 0) maxi = 0;

return maxi;
```

> Time Complexity : O(N) <br>
> Space Complexity : O(1)

---

#### Follow up : Can you print subarray with maxi sum (any subarrays )

```cpp
int sum = 0, maxi = INT_MIN;
int start = 0;
int ansStart = -1, ansEnd = -1;
for(int i = 0; i < nums.size(); i++) {
    if(sum == 0) start = i;//we are starting a new subarray
    sum += nums[i];

    if(sum > maxi) {
       maxi = sum;
       ansStart = start;
       ansEnd = i;
    }

    if(sum < 0) {
        sum = 0;
    }
}
```

> Time : Still O(N) <br>
> Space : O(1)
