# Problem Statement : Find intersection of Two Linked Lists

### _Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null._

```cpp
Input:
List 1 = [1,3,1,2,4], List 2 = [3,2,4]
Output:
2
```

```cpp
Example 2:

Input:
 List1 = [1,2,7], List 2 = [2,8,1]
Output:
 Null
```

```cpp
Example 3:

Input:
 List1 = [1,2,8,7,6], List 2 = [2,8,1,3, 8, 7, 6]
Output:
 8
```

---

#### Approach 1 : Brute Force

- Here we are trying to solve the problem by introducing the thing that it is not the number we are looking for in this same case. We are instead finding out the reference node which has the same number and the same reference.

- we choose any one list to check node is present in the other list or not.
- Iterate through the other list. Here, it is the first one.
- check if the both intersection nodes are the same. if yes we return the answer else we move until we meet the end.
- if the entire second list is completed and no intersection are found between provided lists. We retun NULL.

```cpp
    ListNode* intersectionPresent(ListNode* head1, ListNode* head2) {
        while(head2 != NULL) {
            ListNode* temp = head1;
            while(temp != NULL) {
                //if nodes are same condition
                if (temp == head2)
            }
        }
    }
```

> TC : O(M x N)

---

#### Approach 2 : Hashing

- Traverse the linked list 1 , hash the node address instead of the number. (so basically the whole node)
- We again iterate for linked list 2 and we hash these nodes , now we try to find this in the hash table if this node is already hashed or not.
- when the nodes match for the hash value we return the intersection

> TC : O(N + M) {assuming that hashing takes time complexity of O(1)}
> SC : O(N) -> hashing all the nodes of linked list 1

---

### Best Approach : We need to remove the O(N) space

#### Case 1:

- we can have 2 different dummy nodes and we try to put them at the head of each linked list 1 and 2. we try to find the length of both the linked list.
- We can then calculate the difference in length of the two linked list 1 and 2. we then put the dummy node of that list that is longer and move that by that particular distance.
- then we start traversing both the dummy node simultaneously and move until both the dummy nodes meet at the same point.
- once we get it we get the intersection point .

> So basic idea is calculate the difference in length of the linked list and place the dummy node 1 at the head of short linked list and for dummy 2 move it forward until the difference in bigger linked list. Then move both of them simultaneously, if both of them have intersectino they will both meet at same point.

> TC : O(M) + O(M-N) + O(N) ~ O(2M) -> {M : is length of longer linked list, and we calculate the length simultaneously}
> SC : O(1)

---

#### Case 2 : (preferable Way)

- Here, we go in similar fashion, we keep both the dummy node 1 and 2 on head of the linked list.
- we start moving both of them simultaneously until one of them reaches the null point. { 1->2->3->NULL }
- once one of the dummy node reaches the NULL, we re-initialize the dummy node to head of ANOTHER linked list.
- we again continue going forward simultaneously, we will again find another dummy node reach NULL and we again place this dummy node
- to Another linked list head.
- And it will meet at the same point if we do this. and then we can say we found the intersection .

> TC : O(2 M)
> SC : O(1)
