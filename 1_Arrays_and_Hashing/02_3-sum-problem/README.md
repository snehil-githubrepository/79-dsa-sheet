# 3_Sum : Problem Statement

### _Given an array of N integers, <br> your task is to find unique triplets that add up to give a sum of zero. <br> In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] <br> such that i!=j, j!=k, k!=i, and their sum is equal to zero._

_Example 1:<br>
Input: nums = [-1,0,1,2,-1,-4]<br>
Output: [[-1,-1,2],[-1,0,1]]_

_Example 2:<br>
Input: nums = [0,1,1]<br>
Output: []_

_Example 3:<br>
Input: nums = [0,0,0]<br>
Output: [[0,0,0]]_

---

- 1. _Brute force_
     > Let's try all the triplets that give the sum zero and we return only the unique ones

  ```cpp
      set<vector<int>> st;
      for(i = 0; i < n; i++) {
          for(j = i+1; j < n; j++) {
              for(k = j+1; k < n; k++) {
                  if(a[i]+a[j]+a[k] == 0) {
                      //store triplet {a[i], a[j], a[k]}
                      vector<int> temp = {a[i], a[j], a[k]}
                      sort(temp.begin(), temp.end());
                      st.insert(temp);
                  }
              }
          }
      }
      vector<vector<int>> ans(st.begin(), st.end());
      return ans;
  ```

  _now for avoiding storing duplicate triplets we can actually sort them out, now if we do get duplicate we will have to just sort it to avoid using that again_
  <br>
  _for storing unique we use : set_

  > TIME Complexity = O(n^3) x log(no. of unique triplets)
  > Space Complexity = 2 x O(no. of triplets)

---

- 2. _Better approach_

  we need to get rid of a[k] loop and make the complexity atleast N^2 , So what we can do here is :<br>
  arr[i] + arr[j] + arr[k] = 0;<br>
  arr[k] = -(arr[i] + arr[j])

  - Now how do we look up for this arr[k] than a linear search --> hashing

  > DRY RUN : we maintain a hashmap and keep putting the elements that are traced already by j pointer in hashset which are not part of either "i" or "j".<br> But when we go for next loop of "i" we will have to empty the hashset

  - Let's understand this through code :

```cpp
    set<vector<int>> st;

    for(int i = 0; i < n; i++) {
        //so that we empty hashset
        set<int> hashset;
        for(int j = i+1; j < n; j++) {
            int third = -(a[i] + a[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
```

- Let's analyze _Time Complexity_ > O(N^2 x Log(N)) //set data structure gives log(N) <br> _Space complexity_ : O(N) + ( O(number of unique triplets ) ) x 2 //for hashset and storing it in the list

---
