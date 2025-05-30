// 875. Koko Eating Bananas
// * ---------------------------------------------------------------------------------------
// * Koko has `n` piles of bananas (`piles[i]` bananas in pile *i*) and exactly `h` hours
// * until the guards return.  She chooses an integer eating speed `k` (bananas/hour).
// * Each hour she picks **one** pile and eats up to `k` bananas from it
// * (if the pile has < k bananas she just finishes it and waits).
// *
// * Goal :  Return the **minimum** integer `k` such that Koko can finish every pile
// *         within `h` hours.
// *
// * ---------------------------------------------------------------------------------------
// *  ❖  Solution 1 – Binary Search on the Speed `k`   (O(n log maxPile))
// * ---------------------------------------------------------------------------------------
// * 1.  Bounds for `k`
// *       • min speed = 1  (must eat at least one banana each hour)
// *       • max speed = max(piles)  (finish the largest pile in one hour)
// *
// * 2.  For a candidate speed `k`
// *       hours for one pile p  =  ceil(p / k)
// *                            =  (p / k) + (p % k != 0)
// *       totalHours            =  Σ hours(p)  over all piles
// *
// * 3.  Binary-search logic
// *       • If totalHours ≤ h  → `k` is **fast enough** → try smaller speeds
// *                              → r = k – 1,  keep best result
// *       • else               → `k` is **too slow**   → increase speed
// *                              → l = k + 1
// *
// * 4.  Termination
// *       The first speed that meets the ≤ h constraint (recorded in `result`)
// *       is the minimal required `k`.
// *
// * Time Complexity :  O(n log maxPile)  
// * Space Complexity:  O(1)
// *
// * Time Stats  (from LeetCode submission):
// *   Runtime : 7 ms
// *   Beats   : 74.55 C++ users
// * Space Stats (from LeetCode submission):
// *   Memory Usage : 23.01 MB
// *   Beats        : 12.58 % of C++ users

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r;                       // best (min) k found so far

        while (l <= r) {
            int k = (l + r) / 2;              // candidate speed
            long long hours = 0;

            // —— compute hours needed at speed k ——
            for (int p : piles)
                hours += (p / k) + ((p % k) != 0);  // ceil(p / k)

            if (hours <= h) {                 // k fast enough → try to slow down
                result = k;                   // record candidate
                r = k - 1;
            } else {                          // k too slow  → speed up
                l = k + 1;
            }
        }
        return result;
    }
};


/****************************************************************************************
*  ❖  Solution 2 – Brute Force   (O(n · maxPile))            << Slower, for reference >>
* ---------------------------------------------------------------------------------------
* • Enumerate every possible speed `k` from 1 to `maxPile`.
* • For each `k` compute total hours exactly as above; return first k with hours ≤ h.
* • Works, but when `maxPile` is large (e.g., 10⁹) this linear scan is far too slow,
*   hence the need for the binary-search optimization above.
*
* Time Complexity :  O(n · maxPile)   → infeasible for big piles
* Space Complexity:  O(1)
****************************************************************************************/
class BruteForceSolution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());

        for (int k = 1; k <= maxPile; ++k) {
            long long hours = 0;
            for (int p : piles)
                hours += (p + k - 1) / k;     // ceil(p / k)

            if (hours <= h) return k;         // first feasible k
        }
        return maxPile;                       // theoretically unreachable
    }
};
