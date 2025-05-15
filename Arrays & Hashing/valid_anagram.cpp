// Valid Anagram
// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.
// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
// Example 1:
// Input: s = "racecar", t = "carrace"
// Output: true

// Example 2:
// Input: s = "jar", t = "jam"
// Output: false

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
