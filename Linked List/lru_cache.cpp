// 146. LRU Cache  
// ---------------------------------------------------------
// Problem:
// Design a data structure that simulates an LRU (Least Recently Used) cache:
// - If `put()` exceeds capacity, evict the least recently used key.
// - `get()` and `put()` must run in average O(1) time.
//
// Approach: Hash Map + Pair Frequency
// - `put()` takes **O(capacity)** time in the worst case due to a full scan
//   to find the LRU entry — hence not strictly O(1).
//
// Better alternatives (not used here):
// - Use a combination of `unordered_map` and `doubly linked list`
//   to achieve true O(1) for both `get` and `put`.
//
// Time Complexity:
// - get(): O(1)
// - put(): O(capacity) worst-case due to scan
//
// Space Complexity: O(capacity)
//
// Runtime     : 240 ms   (Beats 5.05%)  
// Memory Usage: 170.86 MB (Beats 99.18%)
// ---------------------------------------------------------


// Solution:
class LRUCache {
    struct Entry {
        int  value;
        long lastUse;              // logical timestamp
    };

    int capacity;                  // fixed size
    long tick = 0;                 // global counter (monotonically increasing)
    std::unordered_map<int, Entry> cache;
public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;           // not present

        it->second.lastUse = ++tick;                // update recency
        return it->second.value;

    }
    
    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {                    // key already present
            it->second.value   = value;
            it->second.lastUse = ++tick;
            return;
        }

        /* key is new → check capacity */
        if ((int)cache.size() == capacity) {        // must evict LRU
            long bestTime = std::numeric_limits<long>::max();
            int  lruKey   = -1;

            for (const auto& [k, entry] : cache) {  // O(capacity) scan
                if (entry.lastUse < bestTime) {
                    bestTime = entry.lastUse;
                    lruKey   = k;
                }
            }
            cache.erase(lruKey);
        }

        cache[key] = {value, ++tick};               // insert new entry
        
    }
};

