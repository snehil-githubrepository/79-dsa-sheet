# Problem Statement : Find middle element in a Linked List

### _Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node._

```cpp
Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
```

```cpp
Example 1:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
```

---

#### Method :

- Well there's 2 pointers that we start from the beginning of the list (slow and fast).
- Once we start the looping statement we go until either fast gets till NULL (i.e. end of the list) or fast-> next gets NULL
- we keep incrementing slow (one by one) => `slow = slow -> next`
- we keep incrementing fast (two steps at once) => `fast = fast -> next -> next`

> Once We finish the looping statement we will in default have our slow pointer element as our answer. even if its a even length list or a odd length list according to the problem statement.
