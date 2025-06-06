// 4. Median of Two Sorted Arrays
// ------------------------------
// Problem:
// Given two sorted arrays nums1 and nums2 of sizes m and n respectively,
// return the median of the two sorted arrays in O(log(m + n)) time.

// Approach: Binary Search on the Smaller Array (Partitioning Method)

// logic:
//
// 1. We always binary search on the smaller array (nums1) to reduce time complexity.
//    If nums1 is larger, we swap it with nums2.
//
// 2. We want to partition both arrays such that the left half (L) contains the first
//    ⌊(m + n + 1)/2⌋ elements (for odd/even combined lengths).
//
//    Let i = partition index in nums1 and j = partition index in nums2.
//    Since total elements in left = k = (m + n + 1) / 2,
//    → j = k - i
//
// 3. Our goal is to make sure:
//    ▸ Aleft ≤ Bright  → (nums1[i - 1] ≤ nums2[j])
//    ▸ Bleft ≤ Aright  → (nums2[j - 1] ≤ nums1[i])
//    If both conditions are satisfied, we found the correct partition.
//
// 4. We use edge-safe values:
//    ▸ Aleft = -∞ if i == 0 (nothing on the left of nums1)
//    ▸ Aright = ∞ if i == a (nothing on the right of nums1)
//    ▸ Same for nums2's boundaries
//    This allows us to safely handle edge partitions without out-of-bounds errors.
//
// 5. Final median:
//    ▸ If total is odd → return max(Aleft, Bleft)
//    ▸ If total is even → return (max(Aleft, Bleft) + min(Aright, Bright)) / 2
// --------------------------------------------------------------
// - Why use infinity and -infinity for edge cases?  
//   - If i = 0 (no elements from nums1), Aleft = -∞ ensures it’s less than any Bright.
//   - If i = a (all elements from nums1), Aright = ∞ ensures it’s greater than any Bleft.
//   - Similarly for nums2 with j = 0 or j = b. This simplifies comparisons at boundaries.
// - Comparison criteria (Aleft <= Bright and Bleft <= Aright):
//   - Aleft <= Bright ensures the largest element in nums1’s left part doesn’t exceed
//     the smallest in nums2’s right part, maintaining sorted order across partitions.
//   - Bleft <= Aright ensures the largest element in nums2’s left part doesn’t exceed
//     the smallest in nums1’s right part, ensuring all left elements are <= all right elements.
//   - Together, these conditions confirm a valid partition where the left half is fully
//     separated from the right half in the merged order.
// - Why max(Aleft, Bleft) for odd case, and max/min for even case?
//   - Odd total: The median is the middle element, which is the largest in the left half
//     (k elements), so we take max(Aleft, Bleft).
//   - Even total: The median is the average of the two middle elements—the largest in
//     the left half (max(Aleft, Bleft)) and the smallest in the right half (min(Aright, Bright)).
//
// Time Complexity:
//   O(log(min(m, n))) – efficient binary search on smaller array
// Space Complexity:
//   O(1) – constant extra space
//
// Time Stats (from LeetCode submission):
//   Runtime : 0 ms  
//   Beats   : 100 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 95.15 MB
//   Beats        : 61.62 % of C++ users


// Solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
int a = nums1.size();
        int b = nums2.size();
        // Ensure nums1 is the smaller array
        if (a > b) {
            swap(nums1, nums2);
            swap(a, b);
        }
        int total = a + b;
        int k = (total + 1) / 2; // Number of elements on the left side

        int l = 0;
        int r = a; // i can be 0 to a inclusive

        while (l <= r) {
            int i = (l + r) / 2; // Partition index for nums1
            int j = k - i;           // Partition index for nums2

            // Elements at the partition boundaries
            double Aleft = (i > 0 ? nums1[i - 1] : -numeric_limits<double>::infinity());
            double Aright = (i < a ? nums1[i] : numeric_limits<double>::infinity());
            double Bleft = (j > 0 ? nums2[j - 1] : -numeric_limits<double>::infinity());
            double Bright = (j < b ? nums2[j] : numeric_limits<double>::infinity());

            if (Aleft <= Bright && Bleft <= Aright) {
                // Correct partition found
                if (total % 2) {
                    return max(Aleft, Bleft); // Odd case: median is the max of left elements
                }
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2; // Even case
            } else if (Aleft > Bright) {
                r = i - 1; // Too many elements from nums1
            } else {
                l = i + 1; // Too few elements from nums1 (Bleft > Aright)
            }
        }
        // Should always find a partition, but return 0 if not (for completeness)
        return 0;
        
    }
};



