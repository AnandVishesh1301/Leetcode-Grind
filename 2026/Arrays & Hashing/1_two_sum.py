from typing import DefaultDict


class Solution:
    def __init__(self, prevMap) -> None:
        self.prevMap = {}

    def twoSum(self, nums: list[int], target: int) -> list[int]:
        """
        Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

        You may assume that each input would have exactly one solution, and you may not use the same element twice.

        You can return the answer in any order.

         Example:
             Input: nums = [3,2,4], target = 6
             Output: [1,2]

        """
        prevMap = {}

        for i, num in enumerate(nums):
            comp = target - num

            # Check if the comp in teh current hash map
            if comp in prevMap:
                return [prevMap[comp], i]

            # Else add to the map
            prevMap[num] = i
        return []


def main():
    # solution: Solution = Solution()

    testCases = DefaultDict(int)
    testCases = {tuple([2, 7, 11, 15]): 9, tuple([3, 2, 4]): 6, tuple([3, 3]): 6}
    testMap = {}

    # Run all the test cases
    for keys, values in testCases.items():
        solution: Solution = Solution(testMap)
        print(
            f" nums = {list(keys)}, target = {values}, Output = {solution.twoSum(list(keys), values)}"
        )


# Execute main if the script is run directly
if __name__ == "__main__":
    main()
