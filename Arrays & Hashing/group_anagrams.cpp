// Group Anagrams
// Given an array of strings strs, group all anagrams together. You can return the output in any order.
// An anagram is a string that contains the exact same characters as another string, but the order of characters can be different.
//
// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Example 2:
// Input: strs = [""]
// Output: [[""]]
//
// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
//
// Approach:
// - Two strings are anagrams if they have the same character frequencies.
// - For each word, we generate a unique *hash* based on the frequency of characters.
// - This hash is used as a key in an unordered_map to group anagrams.
//   Example: "eat", "tea", and "ate" all result in the same hash string, so they get grouped together.
// - The hash is constructed by counting character frequencies in a 26-length array, and serializing it as a string with `$` delimiters.
// - The map stores the key and the index of its corresponding group in the result vector.
//
// Why `$` in hash? To avoid key collisions like "11" vs "1&1", we separate each count with a special character.
//
// Time Complexity: O(N * L) where N is the number of strings and L is the average length of each string.
//                    - Each string is processed once to generate its frequency map in O(L) time.
// Space Complexity: O(N * L) for storing the groups and keys in the map.
//
// Solution Stats:
// Runtime: 60 ms, Beats: 14.05 % of C++ users


#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Helper function to generate a unique hash based on character frequency
string getHash(string &s) {
    string hash;
    vector<int> freq(26, 0);

    // Count frequency of each character in the string
    for (char c : s) {
        freq[c - 'a'] += 1;
    }

    // Convert frequency array into a delimited string to serve as a hash key
    for (int i = 0; i < 26; i++) {
        hash.append(to_string(freq[i]));
        hash.append("$");  // Use '$' to clearly separate counts and avoid collision
    }

    return hash;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> umap;  // Maps hash to index of group in result

        for (int i = 0; i < strs.size(); i++) {
            string key = getHash(strs[i]);

            // If this hash hasn't been seen before, create a new group
            if (umap.find(key) == umap.end()) {
                umap[key] = result.size();
                result.push_back({});
            }

            // Add the word to its corresponding group
            result[umap[key]].push_back(strs[i]);
        }

        return result;
    }
};