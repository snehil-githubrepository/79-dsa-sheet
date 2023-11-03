# Problem Statement : Detect a Cycle in a Linked List

### _Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Return true if there is a cycle in the linked list. Otherwise, return false._

```cpp
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
```

```cpp
Example 2:

Input: head = [1,2], pos = 0
Output: true
```

```cpp
Example 3:

Input: head = [1], pos = -1
Output: false
```

---

#### Approach 1: Hashing

- use hash table for storing the nodes
- Start iterating through the list
- `If` current `node` is present in the hash table , this indicates cycle present in the list and returns `True`.
- `Else` insert node in hash table and move ahead and if we reach the end of the list we can return `False`.

> code :

```cpp
    bool cycleDetect(node* head) {
        unordered_set<node*> hashTable;
        while(head != NULL) {
            if(hashTable.find(head) != hashTable.end()) return true;
            hashTable.insert(head);
            head = head->next;
        }
        return false;
    }
```

> TC : o(N)
> SC : O(N)

---

#### Best Approach : Slow and Fast pointer

- use the slow and fast pointer, initially keep both of them at head of linked list
- iterate through the list until fast equals NULL.
- If FAST do reach NULL that means there is no loop in the list.
- If fast equals slow => there is loop in the linked list => return true

> Code in cpp file

---
