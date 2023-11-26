## Problem Statement : N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle [HARD]

### _The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the **n-queens puzzle**. You may return the answer in **any order**. Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively._

```cpp
Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
```

```cpp
Example 2:

Input: n = 1
Output: [["Q"]]
```

---

> Rules to Place Queen

- Every row should have a Q
- Every col should have a Q
- None of the Q should attack each other

---

## Approach 1

```
Q . . .
. Q . .
. . Q .
. . . Q

not allowed this one (because they will attack each other)

. Q . .
. . . Q
Q . . .
. . Q .

This seems to be working bcz no Queen attack each other and there's queen in each row and col

we can get one more

. . Q .
Q . . .
. . . Q
. Q . .

Here as well we have followed all rules

```

- We just have to give ways in which we can place N queens which should also validate those 3 rules

_One thing is we have to generate all possible ways and that gives me idea of Recursion for the question_

```
                        . . . .
                        . . . .
                        . . . .
         -------------  . . . .  -----------------
         |               /     \                 |
         |              /       \                |
      Q . . .      . . . .       . . . .      . . . .
      . . . .      Q . . .       . . . .      . . . .
      . . . .      . . . .       Q . . .      . . . .
      . . . .      . . . .       . . . .      Q . . .
       /  \
      /    \
Q . . .   Q . . .
. . . .   . . Q .
. Q . .   . . . .
. . . .   . Q . .
   |        /
   NP   Q . . .
        . . Q .
        . . . .
        . Q . .
           |
           NP

NP : Not Possible to generate all queens so we go back to previous case (backtrack) and before going back remove the place Q

and in same way we can go over each possibility

```

```cpp
f(col) {
    //can fill in the cell or not so that queen do not attack
    bool fill  = false;
    for(row = 0 -> n-1) {
        if(fill) {
            // fill up Queen at given row and col
        }
        f(col+1)
        //backtrack step after this so that we remove Q bcz combination is not possible
    }
}
```

```
     -----n-----
    | _________ |
   n| _________ |
    | _________ |
    =============
        vector

        ____=> another vector
```

### Recursion Code : C++

```cpp
  public:
    // we know queen can go 8 ways -> yea?
    //  \ | /
    // -- Q --
    //  / | \

    // but here's the thing we move to next col to check on the left only if there's queen
        //  \
        // -- Q
        //  /

    //we only need these 3 direction to check for safe

   bool isSafe(int row, int col, vec<string> board, int n) {
    //O(N)
    //checking upper diagonal
    int duprow = r;
    int dupcol = c;

    while(row >= 0 and col >= 0) {
        if(board[row][col]=='Q') return false; //can't place here
        row--;
        col--;
    }
    //O(N)
    //horizontal check
    col = dupcol;
    row = duprow;

    while(col >=0) { //we have to check till end col if the queen can be attacked or not. Not just the col-1 but till first col on left
        if(board[row][col] == 'Q') return false;
        col--;
    }
    //O(N)
    //check lower diagonal
    col = dupcol;row=duprow;
    while(row < n and col >=0) { //col is going left but row is increasing
        if(board[row][col] == 'Q') return false;
        row++;col--;
    }
    //if not queen found then its safe to place
    return true;
   }

  public:
    void solve(int col, board, ans, int n) {
        if(col == n) {
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row ++) { // O(N)
            //safe to place queen or not
            if(isSafe(row, col, board, n)) { // O(3N)
                board[row][col] = 'Q';
                solve(col+1, board, ans, n);
                //backtrack in case it doesn't work out
                board[row][col] = '.';
            }
        }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.'); // initialize the inside vector with "."  => | . | . | . | . |
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      solve(0, board, ans, n);
      return ans;
    }
```

---

## Since it is taking up a lot of Time complexity we should learn Hashing to remove those O(3N)

## Optimizations

- we can keep a hash of rows to check that Q is placed in the particular row or not for the horizontal thing

```
  0 . . . .
  1 Q . . .
  2 . . . .
  3 . Q . .

  hash : |___|_P_|___|_P_|
           0   1    2  3
  P -> placed
```

- for lower diagonal
- one interesting thing let's see for 4 x 4

```
       . . . .
       . . . .
       . . . .
       . . . .

        0  1  2  3
      ______________
  0  |  0  1  2  3
  1  |  1  2  3  4
  2  |  2  3  4  5
  3  |  3  4  5  6

for this sum of row + col = cell value

we see a pattern here on the lower diagonal thingy
```

- how about we maintain hashing of the sum of row and col. Now size = (2n-1) -> 2x4 - 1 => 7

```
    hash : |___|___|___|___|___|___|___|
             0   1   2   3   4   5   6

             now when we fill one of these cell we can't place it in any row whose sum of row + col = one of these filled indexes.
```

- For Upper diagonal

> formula : (n-1) + (col-row)

so basically we fill the thing in same way but for upper diagonal

```
        0  1  2  3
      ______________
  0  |  3  4  5  6
  1  |  2  3  4  5
  2  |  1  2  3  4
  3  |  0  1  2  3


hash : |___|___|___|___|___|___|___|
         0   1   2   3   4   5   6

         if we find queen we mark it as 1 in these hash value
```

#### Code in the Cpp file

---
