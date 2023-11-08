## Problem Statement : Print All Subsequences

### _Given a string, find all the possible subsequences of the string._

```cpp
Example 1:
Input: str = "abc"
Output: a ab abc ac b bc c
```

```cpp
Example 2:
Input: str = "aa"
Output: a a aa
```

---

## Observations

- We can say that in a brute force manner we can generate => 2^n subsequences of the particular string. (n is length of string)

#### Approach 1 : Using Bit Manipulation

> Understand this first : when i write (1<<i) or to be specific if i write eg. 1<<2 => 1 0 0 {2 zeros will be kept on right first and then 1 will be kept on left}
> <br/>

> So if you do a 1<<i => it means shift 1 to left by i no. of zeros, in bit manipulation.

##### iMPORTANT fORMULA

- Now, If we had to check ith bit is set or not, we could just have `cpp 
[(n&(1<<i)) != 0]`

##### IMPORTANT THING TO UNDERSTAND

```
eg. (1 0 1)
  & (1 0 0)
   ----------
     1 0 0 => {not equal to 0}

============================

     (1 0 1)
   & (0 1 0)
   -----------
      0 0 0  => {2nd bit is not set => equal to 0}

```

> sOLUTION nOW

---

- we know that properly there will be 2^n subsequences. Let's write numbers from 0 to n-1

```
eg. n = 8 ,  "abc"
    2 1 0 <= Indexing
    ------
0 = 0 0 0 => " " {empty substring}
1 = 0 0 1 => "a"
2=  0 1 0 => "b"
3=  0 1 1 => "ab"
4=  1 0 0 => "c"
5=  1 0 1 => "ac"
6=  1 1 0 => "bc"
7=  1 1 1 => "abc"

=======

Now, let's say 0 -> not picking up element in subsequence, 1 ->pick up element in subsequence , we get above subsequences
```

```cpp
for(i = 0 -> 2^n - 1) // or for(i = 0 -> (1<<n)-1 )
{
    sub = "";
    for(i = 0 -> n-1) {
        if(num & (1<<i)) {
            sub += s[i];
        }
    }
}
print(sub)
```

**Main Code**

```cpp
    //POWER SET
    //we can apply same logic for vector<int> as well instead of string

    //TC : O(2^n x n)
    //SC : O(1)
    vector<string> AllPossibleStrings(string s) {
        int n = s.length();
        vector<string>ans;
        for (int num = 0; num < (1 << n); num++) {
            string sub = "";
            for (int i = 0; i < n; i++) {
                //check if the ith bit is set or not
                if (num & (1 << i)) {
                    sub += s[i];
                }
            }
            if (sub.length() > 0) {
                ans.push_back(sub);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
```

> TC : O(2^n x n)
> SC : O(1)

---

#### Approach 2 : Recursion (Backtracking)

- Maintain a temp string (say f),which is empty initally.
- Now you have two options,either you can pick the character or not pick the character and move to the next index.
- Firstly we pick the character at ith index and then move to the next index.(f + s[i])
- If the base condition is hit,i.e i==s.length() ,then we print the temp string and return.
- Now while backtracking we have to pop the last character since now we have to implement the non-pick condition and then move to next index.

> TC : O(2^n)
> Sc : O(N) , {Recursive Stack Space}

---
