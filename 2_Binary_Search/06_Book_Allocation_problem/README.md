# Problem Statement : Book Allocation Problem

**`Medium`**

---

## _Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students._

## _Allocate books in such a way that:_

## _1. Each student gets at least one book. <br>2. Each book should be allocated to only one student. <br>3. Book allocation should be in a contiguous manner._

## _You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1_

```cpp
Example 1:
Input Format: n = 4, m = 2, arr[] = {12, 34, 67, 90}
Result: 113
Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and the other will get the last one.
```

```cpp
Example 2:
Input Format: n = 5, m = 4, arr[] = {25, 46, 28, 49, 24}
Result: 71
Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.
```

---

#### 1. Brute Force

- Eg. arr[] = [25, 46, 28, 49, 24], students = 4

- 25 | 46 | 28 | 49 24 => 73
- 25 | 46 | 28 49 | 24 => 77
- 25 | 46 28| 49 | 24 => 74
- 25 46 | 28 | 49 | 24 => 71

> Possible combination : out of these only 4th possibility is going to give us the minimum pages for a student to read, there are no other possible iterations

> So we return ans = 71

- Now, if we don't have enough books for each student ,i.e. arr.length < students => return -1

- One thing we can say is , **whenever we have max of min or min of max => binary Search will be applied**

- let's see the brute force first:
- We should first start from theh biggest number in the array -> 49 , this is the max someone can be assigned from the array

```
1 -> 25 {i won't take 46 for this student because then i will exceed my cur max 49}
2 -> 46 {i won't take 28 for this student because then i will exceed my cur max 49}
3 -> 28 {i won't take 49 for this student because then i will exceed my cur max 49}
4 -> 39 {i won't take 24 for this student because then i will exceed my cur max 49}
5 -> 24 = we see we got to have more students, than required and we can't have that, i.e. now we have to fit a extra book to one student
```

- Now, we will keep increasing the biggest number that we got in array, i.e. 49 -> 50 -> 51 -> ..... -> 70

- What we will see at 70 is that :

```
1 -> 25 {i won't take 46 for this student because then i will exceed my cur max 70}
2 -> 46 {i won't take 28 for this student because then i will exceed my cur max 70}
3 -> 28 {i won't take 49 for this student because then i will exceed my cur max 70}
4 -> 39 {i won't take 24 for this student because then i will exceed my cur max 70}
5 -> 24 = we see again we got to have more students, than required and we can't have that, i.e. now we have to fit a extra book to one student
```

- Now, if i increase my cur max sum to 70 -> 71
- what we see is :

```js
1 -> 25 46 {we can take it as now the cur max = 71 & (25 + 46 = 71), We can't take 28 as it will exceed 71}
2 -> 28 {i won't take 49 for this student because then i will exceed my cur max 71}
3 -> 39 {i won't take 24 for this student because then i will exceed my cur max 71}
4 -> 24 = we distributed all the books to 4 students and managed to get sum as 71.
```

- The max possible scenario can be the arr[] = {25, 46, 28, 39, 24} , students = 1 => all the books will go to 1 which will be worst case scenario, Summation of all the array elements will be our answer

> The range has been figured out from : max(arr[]) -> sum(arr[])

> Linear Search (Brute force)

```cpp
fn(arr, pages) { //pages => max pages student can hold
    st = 1; //initially we are at st 1
    pagesStudent = 0; //0 pages initially for student 1
    //lets imagine pages = 71

    for(i = 0 -> n-1) {
        if(pagesStudent + arr[i] <= pages) {
            pagesStudent += arr[i];
        }
        else { //25 + 46 = 71 + 28 = 99 > 71
            st ++;
            pagesStudent = arr[i];
        }
    }
    return st;
}

low = max(arr)
high = sum(arr)

for(pages = low -> high) {
    cntStudents  = fn(ar, pages);
    if(cntStudents== m) { //m = no of students
        return pages;
    }
}
```

> TC : O(sum - max + 1) x O(N) => linear search

---

#### 2. Binary Search

**_whenever the question Revolves around max, min we should think of binary search_**

- we know the answer will be from

  - low = max(arr) , high = sum(arr)
  - 49 -> 172

- What we also know is, if i use 49 pages we will end up in 5 students and if we use 172 we will end up on 1 student having all books, hence answer would lie somewhere in the middle of this range as we have 4 students
- we have 71 in middle and students were 4

```
49                              172
lo                              hi

mid = 49 + 172 / 2 = 110

1 -> 25, 46, 28
2 -> 49, 24

but we need 4 students and we completed this in just 2, so we need to decrease the mid ,anything on right is not possible so we cancel that and see on the left.

=> new High = 109

=> new mid = 49 + 109 / 2 = 78

1 -> 25, 46
2 => 28, 49
3 -> 24

we got 3 students but we need exactly 4 so we move high to 77

=> new High = 77

=> new mid = 49 + 77 / 2 = 63

with 63 we will get 5 students => not possible we move the low now to 64

64                                    77
lo                                    hi

mid = 70

with 70 we can't be able to do this so we move the low to 71

71                      77
lo                      hi

mid = 71 + 77 / 2 =74

1 -> 25, 46
2 -> 28
3-> 49
4 -> 24

we do have 4 students but lets try more towards left for a min value

---

71              73
lo              hi

mid = 72

we have 4 students lets last try 71 as well because even 72 will give 4 students

71
lo
hi
mid

For 71 :

we have 4 students and this is the least we can go , we can now move the low to 72 but now condition is lo > hi so we stop

```

> Tc : O(Log (sum - max + 1)) x O(N)
> SC : O(1)

---
