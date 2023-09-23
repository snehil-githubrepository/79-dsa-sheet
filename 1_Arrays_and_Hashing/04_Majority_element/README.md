# Majority Elements(>N/3 times) : Problem Statement

---

### _Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector_

```
_Example 1:<br>
Input: N = 5, array[] = {1,2,2,3,2}<br>
Result: 2_
```

```
_Example 2:<br>
Input : N = 6, array[] = {11,33,33,11,33,11} <br>
Result: 11 33_
```

---

#### 1. Brute force

_Here, We have to return all the integers that appear more than floor(n/3) times in the array (it is more than and not equal to)_

- Some observations here are that in the algorithm there can be only 2 elements that would follow the above thing. and the ans will have at max 2 integers that are greater than floor(n/3).

_Go through whole array and check for elements appearing more than floor(n/3) times._

- Pseudo Code :

```cpp
vector<int> ans;
for(i = 0 -> n-1) { //o(n)
    if(ans.size() == 0 || ans[0] != nums[i]) {
        cnt = 0;
        for(j = 0 -> n-1) { //O(N)
            if(nums[j] == nums[i]) {
                cnt++;
            }
        }
        if(cnt > (N/3)) {
            ans.pb(nums[i]);
        }
    }
    if(ans.size() == 2) break;
}
sort(ans.begin(), ans.end()); //its only 2 elements so no addition to time complexity
return ans;
```

> Time Complexity : O(N ^ 2) <br>
> Space Complexity : O(1)

---

#### 2. Better solution

> Hashing is what we can think of for the count of these things

- We can keep : (number, count)

-iterate over the array and do what we do for hashmaps

- we first iterated over the array and stored everything in the hashmap then we iterated over hashmap for comparing it with {n/3}

- _but we can do better, we first calculate value of floor(n/3) and look for values in hashmap while storing if they are more than n/3, we have got our ans: hence we store it in the answer array_

- Pseudo Code :

```cpp
vector<int> ls;
unordered_map<int, int> mp;
min = floor(n/3) + 1;
for(i= 0-> n-1)  //o(N)
{
    //if element doesn't appear it automatically takes it as 0
    mp[arr[i]]++;
    if(mp[arr[i]] == min) ls.add(arr[i]);
}
```

> Time Complexity : O(N) x O(1), O(1) for the unordered_map<br>
> Space Complexity : O(N)

---

### 3. Most Optimal Code

```cpp
    cnt1 = 0, cnt2 = 0;
    int el1 , el2;

    for(i = 0-> n-1) {
        if(cnt1 ==0 && nums[i] != el2) {
            cnt1 = 1;
            el1 = nums[i]
        }
        else if(cnt2 == 0 && nums[i] != el1) {
            cnt2= 1;
            el2 = nums[i];
        }
        else if(el1 == nums[i] ) cnt1++;
        else if(el2 == nums[i] ) cnt2++;
        else {
            cnt1 --, cnt2--;
        }
    }

```

- we are keeping track of 2 elements and their count is stored in cnt1 and cnt2 and these 2 elements are stored as el1, el2.
- we keep updating these 2 elements on basis of increasing their counter and keeping track that it is not common element in el1 and el2.
- we remove the cnt of element if the nums[i] is not equal to the el1 or el2
