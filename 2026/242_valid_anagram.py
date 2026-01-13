from _typeshed import TraceFunction


class Solution:
    """
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    Example: Input: s = "anagram", t = "nagaram"

    Output: true
    """

    def __init__(self) -> None:
        pass

    def isAnagram(self, s: str, t: str) -> bool:
        # Two Wods are anagrams if equal when sorted, TC: O(NlogN)
        # Two Words Anagrams if their hash maps are the same, TC: O(N)

        # Creating FreqMaps of both s and t
        mapS, mapT = {}, {}

        # Populating s
        for i in s:
            if i not in mapS:
                mapS[i] = mapS.get(i, 0) + 1
            else:
                mapS[i] += 1

        # Populating t
        for i in t:
            if i not in mapT:
                mapT[i] = mapT.get(i, 0) + 1
            else:
                mapT[i] += 1

        if mapS == mapT:
            return True

        return False
