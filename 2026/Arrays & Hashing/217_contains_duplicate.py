from collections import defaultdict
from modulefinder import test

class Solution:
    
    """
    217. Contains Duplicate
    Given an integer array nums, return true if any value appears at least twice in the array, 
    and return false if every element is distinct.
    """  
    
    def __init__(self, freqMap) -> None:
       self.freqMap={}

    def containsDuplicate(self, nums: list[int]) -> bool:
        self.freqMap = {}
        
        # Populate the freqMap with nums
        for i in nums:
            #freqMap[i]+=1
            self.freqMap[i] = self.freqMap.get(i,0) + 1
            
            if self.freqMap[i]>1:
                return True

        return False
        
        
       
       

testCases=[[1,2,3,1],[1,2,3,4],[1,1,1,3,3,4,3,2,4,2]]


for nums in testCases:
    sol:Solution = Solution({})
    print(f'test Case: {nums}, Result: {sol.containsDuplicate(nums)}')