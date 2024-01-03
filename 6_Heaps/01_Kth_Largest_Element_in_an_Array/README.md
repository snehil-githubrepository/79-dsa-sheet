# Finding the K-th Largest Element in an Array using Min-Heap

## Introduction

This repository contains an algorithm that efficiently finds the k-th largest element in an array without fully sorting the array. It uses a MinHeap data structure to maintain the k-largest elements encountered so far.

## Algorithm Overview

The algorithm utilizes the following steps:

1. **Initialization:** Initialize an empty MinHeap.
2. **Initial Heap Construction:** Push the first k elements from the array into the MinHeap.
3. **Iterate through the Remaining Elements:**

   - For each element from index k onwards:
     - Check if the element is greater than the smallest element in the MinHeap (obtained by `heap.peek()`).
     - If so, replace the smallest element in the MinHeap with the current element by popping the smallest and pushing the current element.

4. **Result Retrieval:** After iterating through all elements, the MinHeap's top element (`heap.peek()`) represents the k-th largest element in the input array.

## Code Explanation

The code leverages a `MinHeap` class with methods to handle operations like pushing elements into the heap, popping the smallest element, and peeking at the top element. The `findKthLargest` function implements the algorithm by utilizing this MinHeap to efficiently find the k-th largest element in the given array.

## Usage

To use the algorithm:

1. Include the `MinHeap` class implementation in your code.
2. Call the `findKthLargest(nums, k)` function, passing the array `nums` and the value of `k` to find the k-th largest element.

## Complexity Analysis

- **Time Complexity:**
  - Insertion (push): O(log n)
  - Extraction of Minimum Element (pop): O(log n)
  - Peeking (peek): O(1)
  - Search: O(n)
- **Space Complexity:**
  - O(n) where n is the number of elements in the heap.

This algorithm efficiently identifies the k-th largest element in an array by maintaining a MinHeap of the k-largest elements encountered so far, avoiding the need to fully sort the input array.
