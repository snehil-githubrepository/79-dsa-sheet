# LRUCache Implementation in JavaScript

This LRUCache implementation uses a combination of a doubly linked list (DLL) and a hashmap to efficiently store and retrieve key-value pairs while adhering to the Least Recently Used (LRU) cache eviction policy.

## Overview

The LRUCache class initializes with a specified capacity, utilizing a hashmap for key-value storage and a doubly linked list to maintain the order of least recently used keys.

### Operations Supported

- **Initialization**: Initialize the LRUCache with a specified capacity.
- **Get(key)**: Retrieve the value associated with a given key. If the key exists, it updates its usage status.
- **Put(key, value)**: Add or update a key-value pair in the cache. If the cache reaches its capacity, it removes the least recently used key-value pair before adding the new one.

## Approach

- **Initialization**:

  - The LRUCache is initialized with a specified capacity, using a `Map` for key-value storage.
  - Maintains a doubly linked list with `head` and `tail` sentinel nodes to track the order of least recently used keys.

- **Get(key) Operation**:

  - Checks if the key exists in the cache.
  - If found:
    - Moves the corresponding node to the front of the doubly linked list (indicating it's the most recently used).
    - Returns the corresponding value.
  - If not found, returns `-1`.

- **Put(key, value) Operation**:
  - Adds or updates a key-value pair in the cache.
  - If the key already exists:
    - Updates its value.
    - Moves the key to the front in the doubly linked list (indicating it's the most recently used).
  - If the cache reaches its capacity:
    - Removes the least recently used key-value pair by deleting the last node from the doubly linked list and the corresponding entry from the hashmap.
  - Adds the new key-value pair to the cache.
  - Moves the added key to the front in the doubly linked list (indicating it's the most recently used).

## Complexity Analysis

- `get(key)` and `put(key, value)` operations have an average time complexity of O(1) due to using a `Map` for key-value storage and a doubly linked list for maintaining order.
- The space complexity is O(capacity) due to the cache's fixed size.
