// Valid Anagram
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
// Example 1:
// Input: s = "racecar", t = "carrace"
// Output: true

// Example 2:
// Input: s = "jar", t = "jam"
// Output: false

// Approach:
// - Two strings are anagrams if they have the same character counts.
// - We use two unordered hash maps to count the frequency of each character in both strings.
// - If the frequencies match for all characters, the strings are anagrams.
// - First, check if the sizes of both strings are the same — if not, return false early.
// - Then populate both maps and compare each entry in the first map with the second.
//
// Time Complexity: O(N), where N is the length of the strings (assuming both are of similar length).
//                    - Each character is processed once for counting and once for comparison.
// Space Complexity: O(1) — since we are only storing counts of lowercase English letters (fixed size 26).
//                     (Technically O(26) = O(1) in this case)
//
// Solution Stats:
// Runtime: 52 ms, Beats: 33.78% of C++ users


#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> umap_s;
        unordered_map<char,int> umap_t;

        if (s.size()!=t.size()){
            return false;
        }

        //for loop to populate both the hash maps w values and their frequencies
        for(int i=0; i < s.size(); i++){
            umap_s[s[i]]++;
            umap_t[t[i]]++;
        }
        
        for (const auto& pair:umap_s){
            auto it = umap_t.find(pair.first);
            if((it == umap_t.end())  || (pair.second != it -> second)){ // element found && frequency equal
                return false;
            }  
        }
        return true;
        
    }
};
