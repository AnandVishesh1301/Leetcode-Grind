# Car Fleet
# You are given a `target` destination and two arrays:
#   - `position[i]`: starting point of the ith car (in miles from 0)
#   - `speed[i]`: speed of the ith car (in miles/hour)
#
# Each car moves toward the `target`, but:
#   - **A car cannot pass another car ahead of it.**
#   - It may **catch up** and merge into a fleet, moving at the speed of the slower car.
#   - A car fleet is formed when one or more cars arrive together at the target.
#
# Objective:
#   - Return the **total number of car fleets** that will arrive at the destination.
#
# Example:
#   Input : target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
#   Output: 3
#
# Approach:
# - Step 1: Pair each car's position with its speed → (position, speed)
# - Step 2: Sort cars in **descending order of position** so we process cars **closest to the target first**.
#   - We do this Because a car can only be caught by cars behind it, not ahead of it.
# - Step 3: Compute the *time it takes for each car to reach the target: `(target - position) / speed`
# - Step 4: Use a **monotonic stack** to track fleet times:
#   - Push the current car’s time onto the stack.
#   - If a car arrives **earlier or at the same time** as the one ahead (i.e., top of the stack),
#     it merges into the same fleet → pop the faster fleet time.
#   - Otherwise, it starts a new fleet.
#
# Why this works:
# - We process cars from closest to farthest.
# - This guarantees that once a slower car is ahead, no car behind it can pass — they can only merge.
# - The stack will contain the **distinct fleets** as each top value represents a lead car's arrival time.
#
# Time Complexity : O(n log n) → for sorting
# Space Complexity: O(n) → for storing fleet times in stack
#
# Time Stats (from LeetCode submission):
#   Runtime : 229 ms
#   Beats   : 24.33 % of Python users
# Space Stats (from LeetCode submission):
#   Memory Usage : 39.08 MB
#   Beats        : 45.92 % of Python users


## Solution
class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        # Step 1: Pair up position and speed
        pair = [[p, s] for p, s in zip(position, speed)]

        # Step 2: Sort cars by position in descending order (closest to target first)
        pair.sort(reverse=True)

        stack = []  # stack will hold fleet arrival times

        # Step 3: Traverse cars from front-most to back
        for p, s in pair:
            time = (target - p) / s  # Time to reach target
            stack.append(time)       # Assume it's a new fleet

            # Step 4: Merge if car behind reaches earlier or together
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()  # Merge current car with the fleet ahead

        return len(stack)  # Number of distinct fleets
