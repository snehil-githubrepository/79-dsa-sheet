/**
 * @param {number} capacity
 */
var LRUCache = function (capacity) {
  this.capacity = capacity;
  this.cache = new Map();
  this.head = { key: null, value: null, prev: null, next: null };
  this.tail = { key: null, value: null, prev: this.head, next: null };
  this.head.next = this.tail;
};

/**
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function (key) {
  if (this.cache.has(key)) {
    const node = this.cache.get(key);
    this.removeNode(node);
    this.addToFront(node);
    return node.value;
  }
  return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function (key, value) {
  if (this.cache.has(key)) {
    const node = this.cache.get(key);
    node.value = value;
    this.removeNode(node);
    this.addToFront(node);
  } else {
    if (this.cache.size === this.capacity) {
      const removedKey = this.tail.prev.key;
      this.removeNode(this.tail.prev);
      this.cache.delete(removedKey);
    }
    const newNode = { key, value, prev: null, next: null };
    this.cache.set(key, newNode);
    this.addToFront(newNode);
  }
};

// Additional helper functions

/**
 * @param {object} node
 * Helper function to add a node to the front of the linked list
 */
LRUCache.prototype.addToFront = function (node) {
  const headNext = this.head.next;
  this.head.next = node;
  node.prev = this.head;
  node.next = headNext;
  headNext.prev = node;
};

/**
 * @param {object} node
 * Helper function to remove a node from the linked list
 */
LRUCache.prototype.removeNode = function (node) {
  const prevNode = node.prev;
  const nextNode = node.next;
  prevNode.next = nextNode;
  nextNode.prev = prevNode;
};
