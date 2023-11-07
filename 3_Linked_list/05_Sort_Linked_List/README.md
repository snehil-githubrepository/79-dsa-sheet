# Problem Statement : Find intersection of Two Linked Lists

### _Given the `head` of a linked list, return the list after sorting it in **ascending order**._

```cpp
Example 1:

Input:
    head = [4,2,1,3]
Output:
    [1,2,3,4]
```

```cpp
Example 2:

Input:
    head = [-1,5,3,4,0]
Output:
    [-1,0,3,4,5]
```

```cpp
Example 3:

Input: head = []
Output: []
```

---

#### Approach 1

- Initialize a dummy node at start of the list (at head)
- Also initialize a vector
- Traverse the dummy node along the list and push the values of this dummy into vector. (traverse dummy until its NULL)
- Once we have all values in vector -> sort the vector to have numbers in sorted order.
- put the dummy back at head node and now we want to traverse the list one by one and put the values from nums into dummy nodes one by one.
- `dummy -> val = nums[i]` ; and keep moving the variable i till length of the nums vector.
- at the end we will have the list with the right set of sorted values, so just return this list.

> TC : O(N) + O(Nlog N) ~ O(N log(N)) => { N for traversing dummy node and N log n for sorting in nums vector}
> SC : O(N) => {storing the values in nums vector}

---
