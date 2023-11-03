# Problem Statement : Remove N-th node from the end of a Linked List

### _Given the head of a linked list, remove the nth node from the end of the list and return its head._

```cpp
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

```cpp
Example 2:

Input: head = [1], n = 1
Output: []
```

```cpp
Example 3:

Input: head = [1,2], n = 1
Output: [1]
```

```cpp
Example 4:

Input: head = [1,2, 3, 4, 5, 6], n = 6
Output: [2, 3, 4, 5, 6]
```

---

#### Approach 1

- First with the help of Dummy node we iterate over the list to get the length of linked list
- Let's say we save it as `len` variable

> nodePositionFromStart = len - n

- We again start from the start of the list with a new dummy node `t`.
- initially counter is 1 when at start of list for this particular dummy node.
- We go until we get to the position of `nodePositionFromStart`

> We can store the next node that we need to remove => node = t -> next
> And t->next = t->next->next

- now, we can call the internal `delete` function of c++ to delete the node and that deletes the node and link

> Edge Case :

- if N == length of linked list => they are asking to delete 1st node
- initially, we can do is => assign `node = head ; head = head->next; delete(node)`

> TC: O(N) + O(N) = O(2N) {length_of_list + Traversal to the particular node}
> SC: O(1)

---

#### Optimized Solution

- We define a dummy node and assign it to head
- we assign 2 other pointers - fast And Slow to the dummy node initially
- now we will be given `n` to remove that particular nth node from back
- Now, we move `fast` pointer by n no. of steps from the start and reach a node.
- Once fast pointer has covered `n` distance , we start moving both slow and fast pointer by one movement till fast pointer reaches the last node.
- So, Now whenever the fast reaches last node , we will have slow pointer at a node in linked list

> We are supposed to delete slow->next node so now what we need to do is `slow->next = slow->next->next`

- That probably solves the problem but let's see about edge case :

> if N = 6 : deleting the head node
> basically same logic as above will also help for this case only thing is instead of returning head we can make the dummy -> next as our answer as dummy was pointing to head. SO , SIMPLY RETURN 'DUMMY->NEXT'

> TC : O(N) {fast pointer will move "N" till end of linked list}
> SC : O(1)

---
