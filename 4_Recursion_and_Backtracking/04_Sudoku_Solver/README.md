## Problem Statement : SuDoku Solver [HARD]

### _Write a program to solve a Sudoku puzzle by filling the empty cells.<br>A sudoku solution must satisfy **all of the following rules:**<br>Each of the digits `1-9` must occur exactly once in each row.<br>Each of the digits `1-9` must occur exactly once in each column.<br>Each of the digits `1-9` must occur exactly once in each of the 9 `3x3` sub-boxes of the grid.<br>The `'.'` character indicates empty cells._

```cpp
Example 1:

Input:
board =
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]
Output:
[["5","3","4","6","7","8","9","1","2"],
 ["6","7","2","1","9","5","3","4","8"],
 ["1","9","8","3","4","2","5","6","7"],
 ["8","5","9","7","6","1","4","2","3"],
 ["4","2","6","8","5","3","7","9","1"],
 ["7","1","3","9","2","4","8","5","6"],
 ["9","6","1","5","3","7","2","8","4"],
 ["2","8","7","4","1","9","6","3","5"],
 ["3","4","5","2","8","6","1","7","9"]]
```
---

## Some things to Notice : 

- If we see its 3 (3x3) small boards in this big board
- 1 to 9 should appear only once in the same row or same column 
- 1 to 9 only appears once in any 3x3 board 

- If it can't happen than backtrack to previous possibility and try for new combination
- so basically carry on recursion until you fill all the numbers correctly and if not possible backtrack
- Once we found the right match we will return true and return the whole board with right set of numbers
- Since the question stated only 1 valid sudoku we return when we find a TRUE. 

> Most probably there will be many possibilities and the complexity will become huge.
---






