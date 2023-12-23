## Problem Statement : Word Search [Medium]

### _Given an `m x n` grid of characters `board` and a string `word`, return `true` if `word` exists in the grid. The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once._

```cpp
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

```cpp
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

```cpp
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

---

- we are looking for a path to find word

---

> Is there super efficient algorithm for this ? NO => brute force-> backtracking

---

```
  A B C E
  S F C S
  A D E E

  now in each cell let's see neighboring cells for the next character of the word

  On "A" check for neighbors "B" and "S" -> we got "B" => we then go on "B" -> check for neighbor => "C" and "F" and "A" we can't go back to "A" so we see on right and down.

```

---

Let's try recursive backtracking -> using DFS

---
