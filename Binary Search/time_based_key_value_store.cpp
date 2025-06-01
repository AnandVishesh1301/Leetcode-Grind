// Time-Based Key-Value Store
// --------------------------
// Design a data structure that supports:
//    set(key, value, timestamp)   – O(1) append
//    get(key, ts)                 – O(log n) search
//
// Observation
// • All calls to set are guaranteed to have **strictly increasing timestamps**
//   for each key, so each key’s history is naturally kept in sorted order.
//
// Data Layout
// • unordered_map< string, vector< pair<int,string> > > m
//      key  ->  sorted list of (timestamp, value)
//
// get() Strategy
// • Binary-search that per-key vector for the **largest timestamp ≤ ts**.
// • Standard lower/upper-bound pattern: keep a candidate answer and move
//   the search window until l > r.
//
// About `.first` / `.second`
// • vec[mid] is a `std::pair<int,string>` so we access its fields via
//   `.first` (= timestamp) and `.second` (= value).  Indexing like
//   `vec[mid][0]` is **invalid** for a pair.
//
// Complexity
// • set  : O(1)  (amortized push_back)
// • get  : O(log n) per key history
// • Space: O(total #set calls)
//
// Time Stats (from LeetCode submission):
//   Runtime : 35 ms
//   Beats   : 91.68 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 139.98 MB
//   Beats        : 56.54 % of C++ users
// ---------------------------------------------------------------------------
