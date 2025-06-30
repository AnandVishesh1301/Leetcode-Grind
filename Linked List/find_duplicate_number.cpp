// 287. Find the Duplicate Number  
// ---------------------------------------------------------
// Problem:
// Given an array `nums` of n + 1 integers where each value is in [1, n],
// return the one integer that appears more than once.
//
// Approach: Hash Freq Map
// ---------------------------------------------------------
// - We use an unordered_map to store the frequency of each number.
// - First loop populates the frequency map with each number’s count.
// - Second loop traverses the map to identify the number with a count > 1.
// - We return that number as it is the duplicate.
//
// How this works:
//   - Since only one number can repeat, checking frequency > 1 gives the result.
//   - This approach is straightforward and readable.
//
// Time Complexity: O(n) — one pass to build map, one pass to find duplicate
// Space Complexity: O(n) — for the hash map
// ---------------------------------------------------------


// Solution:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> umap;

        // Populate the hash freq map
        for(int i: nums){
            umap[i]++;
        }

        // Traversing throught the map to track teh max val
        int maxVal =INT_MIN;

        for(auto& it: umap){
            if(it.second>1){
                maxVal = it.first;
            }
            else{
                continue;
            }
            
        }
        return maxVal;
    
    }
};
