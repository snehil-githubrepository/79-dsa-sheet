# Asteroid Collision

This algorithm tackles the problem of simulating asteroid collisions within a given array of asteroids represented by integers.

## Problem Description

Given an array `asteroids` of integers where each integer represents an asteroid's size and direction (`positive` means right, `negative` means left), simulate the collisions between these asteroids. If two asteroids meet, the smaller one explodes. If two asteroids are of the same size, they both explode. Two asteroids moving in the same direction will never meet.

### Example:

Input: `asteroids = [8, -8]`

Output: `[]`

Explanation: Both asteroids collide and explode, resulting in no remaining asteroids.

## Approach

The algorithm uses a stack to model the movement and collisions of asteroids:

1. Iterate through each asteroid in the input array.
2. If an asteroid is moving to the right (positive value), push it onto the stack as there's no collision.
3. If an asteroid is moving to the left (negative value):
   - Check for collisions with the asteroids on the stack moving to the right.
   - If the asteroid moving left survives (due to size), it remains on the stack.
   - If the asteroid moving left gets destroyed, update its value to `0`.
4. After the iterations, the remaining asteroids on the stack represent the state after collisions.

## Complexity Analysis

- Time Complexity: O(n), where n is the number of asteroids in the input array. The algorithm iterates through each asteroid once.
- Space Complexity: O(n), where n is the number of asteroids stored in the stack at most.

Feel free to expand on the explanation or add more details as needed!
