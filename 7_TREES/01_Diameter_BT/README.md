# Diameter of Binary Tree

This algorithm calculates the diameter of a binary tree, which is the length of the longest path between any two nodes in a tree. The path may or may not pass through the root.

## Approach

The algorithm uses a recursive approach to traverse the binary tree and compute the diameter. It calculates the height of each node's left and right subtrees while keeping track of the maximum diameter encountered.

### Algorithm Steps

1. Initialize a `diameter` variable to 0.
2. Define a recursive `height` function that computes the height of each node's left and right subtrees.
   - The `height` function returns the depth of the subtree rooted at the current node.
   - It updates the `diameter` variable with the maximum diameter encountered.
3. Start the recursive traversal from the root node.
4. Update the `diameter` variable based on the maximum path between nodes.
5. Return the calculated `diameter`.
