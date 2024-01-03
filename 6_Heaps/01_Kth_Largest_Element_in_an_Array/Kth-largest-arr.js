var findKthLargest = function (nums, k) {
  let heap = new MinHeap();
  for (let i = 0; i < k; i++) {
    heap.push(nums[i]);
  }

  for (let i = k; i < nums.length; i++) {
    if (nums[i] > heap.peek()) {
      heap.pop();
      heap.push(nums[i]);
    }
  }
  return heap.peek();
};
