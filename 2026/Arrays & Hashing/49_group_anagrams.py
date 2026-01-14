from typing import DefaultDict, List


class Solution:
    def __init__(self) -> None:
        pass
        
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        """
        Approach 1:
            - Sort the individual strings in the list, then anagrams will be equal OR 2 Anagrams will have the same freqMap 
        """
        
        # TC: O(M * NlogN), N is the number of char in each string in strs, and m is the total number of strings in strs
        # TO BE OPTIMIZED TO O(N)
        resMap = DefaultDict(list)
               
        for s in strs:
            freqmap = DefaultDict(int)
            
            for char in s:
                freqmap[char] += 1
            
            # Convert to tuple of (char, count) sorted pair
            key = tuple(freqmap.items())
            resMap[key].append(s)
        
        return list(resMap.values())


        # resMap = DefaultDict(List)
        
        
        # for str in strs:
        #      freqmap = DefaultDict(int)
        #      # Convert the string into its freqMap( HashMap)
             
        #      for char in enumerate(str):
        #          freqmap[char] += 1
            
        #      if freqmap in resMap:
        #          (resMap[freqmap]).append(str)
             
        #      else:
        #          resMap[freqmap] = list(str)
                 
        
        # return list(resMap.values())