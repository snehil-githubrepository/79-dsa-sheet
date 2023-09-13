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
      set<vector<int>> st;//to store unique triplets
      for(i = 0; i < n; i++) {
          for(j = i+1; j < n; j++) {
              for(k = j+1; k < n; k++) {
                  if(a[i]+a[j]+a[k] == 0) {
                      //store triplet {a[i], a[j], a[k]}
                      vector<int> temp = {a[i], a[j], a[k]};
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
        set<int> hashset; //to store the unique triplets
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

_3. Most Optimal Solution_ > It will be a Two pointer approach
<br>
what are we looking for -> a[i] + a[j] + a[k] = 0
<br>
_We make the whole array in the sorted order at first._

- Initially , i will be at the start of array and j will be i+1 and k will be kept at the end index of array
- _next, we will try to add up these 3 elements , let's call that variable "x"_
- Remember, i will be const and i will not move
- Now, if we see that x < 0 then eventually we will need to increase the value and for that we will move pointer "j" to the right until the value of "x" becomes 0
- but instead if we see that x > 0 then eventually we will have to decrease the value and for that we will move pointer "k" to the left until value of "x" becomes 0
- _And once we achieve this value of x = 0, we take these 3 elements and store it in triplet and its already sorted_
  -Now, once we achieve value of x = 0, we move both pointer j and k in opposite direction one by one but if the number if repeating we totally skip values for j and k and wait until this condition is hit : k < j and once this happens we stop the loop

  > Now, after loop is completed we move i to next value in right, but it should not be equal to the a[i] value it had before so if there are similar values just skip all of them to generate a new triplet with a new a[i] value. so we take triplet with the same condtions we followed before, where we will stop the loop if j >= k

```cpp
    arr[] = [-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2]
    //we keep moving with i placed at -2 , j placed at -2 and k placed at 2
    //in this way we will generate just 3 triplets
    // {(0, 0, 0), (-1, -1, 2) , (-2, 0, 2)}
    //Rest of code in the cpp file.
```
