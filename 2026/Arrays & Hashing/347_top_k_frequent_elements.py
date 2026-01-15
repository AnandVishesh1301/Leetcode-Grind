class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # TC: O(NlogN); N is the size of nums
        # Populate the freqMap
        freqMap = {}

        for num in nums:
            # freq[nums] +=1
            freqMap[num] = freqMap.get(num, 0) + 1
        # Sort the Hash Map in a reverse order by Values(freq)
        rSorted = dict(sorted(freqMap.items(), key=lambda item: item[1], reverse=True))

        # Return the first ( top ) k elements

        return list(rSorted.keys())[:k]


## TODO: Optimize to TC: O(N)
