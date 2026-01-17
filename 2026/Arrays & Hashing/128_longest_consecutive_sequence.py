class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Populate the Hash Map
        hMap = defaultdict(int)
        lSeq = 0
        #currSeq = 0
        if not nums:
            return 0
        
        # Populate the hash map w the elements in num
        for num in nums:
            hMap[num] = 0


        for num in nums:
            if (num-1) not in hMap:
                currSeq = 1
                currNum = num
                while (currNum + 1) in hMap:
                    currSeq += 1
                    currNum += 1
                
                lSeq = max(currSeq,lSeq)

            else:
                continue
        
        return lSeq



        
        # Traverse through the array to find the longest consecutive sequence 
        #for num in nums:
        #    while ((hMap[num]!=1) and (((num-1) not in hMap)) ):# find the start of a sequence
        #        hMap[num] = 1
        #        currSeq += 1
        #    lSeq = max(currSeq,lSeq)



            


        





# class Solution:
#     def longestConsecutive(self, nums: List[int]) -> int:

#         # Create a freq map (element:visited)
#         # Find the min from that map as initial value to start traversing

#         freqMap = defaultdict(list)

#         lSequence = 0
#         freqMap = {}
#         # freqMap = {element: [freq, visited]}

#         # Populating the freqmap
#         for num in nums:
#             freqMap[num] = [(freqMap.get(num,0) + 1),0 ] # Set the freq, i.e. [0]

#         minKey = min(list(freqMap.keys()))

#         # Start traversing from minKey
#         for k,v in freqMap.items():
#             # Conditions to Traverse Further:
#             # - till "k+1" existsing in teh map, keep updating the longest seq
#             # - When it no more exists, move to teh next unvisited key in teh map and repeat the same
#             if k[minKey][1] == 1: # Skip teh key if already visited
#                 continue
            
#             if
        

    


            


        
        

        
        