/*
 Author:     Matthew Jin, marthew777@gmail.com
 Date:       March 12, 2014
 Problem:    LRU Cache
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/lru-cache/
 Notes:
 Design and implement a data structure for Least Recently Used (LRU) cache. 
 It should support the following operations: get and set. 
 get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 
 Solution: Hash + list.
*/
struct CacheNode{
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
};

class LRUCache{
public:
    LRUCache(int capacity) : size(capacity) {
    }
    
    int get(int key){
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            return cachemap[key]->value;
        }
        else {
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (cachemap.find(key) != cachemap.end()) {
            cachelist.splice(cachelist.begin(), cachelist, cachemap[key]);
            cachemap[key]->value = value;
        }
        else {
            if (size == cachelist.size()) {
                cachemap.erase(cachelist.back().key);
                cachelist.pop_back();
            }
            cachelist.push_front(CacheNode(key, value));
            cachemap[key] = cachelist.begin();
        }
    }
private:
    list<CacheNode> cachelist;
    unordered_map<int, list<CacheNode>::iterator> cachemap;
    int size;
};


class LRUCache {
public:
    struct Cache {
        public:
            int key, value;
            Cache(int k, int v):key(k), value(v) {}
    };
    // @param capacity, an integer
    LRUCache(int capacity) : capacity_(capacity) {}
    
    // @return an integer
    int get(int key) {
        // write your code here
        if (!m_map.count(key)) return -1;
        MoveToHead(key);
        return m_map[key]->value;
    }
    
    void set(int key, int value) {
        // write your code here
         if (!m_map.count(key)) {
             if (m_LRU_cache.size() >= capacity_) {
                 //remove from tail
                 m_map.erase(m_LRU_cache.back().key);
                 m_LRU_cache.pop_back();
             }
             Cache newCache(key, value);
             m_LRU_cache.push_front(newCache);
             m_map[key] = m_LRU_cache.begin();
             return;
         } else {
            m_map[key]->value = value;
            MoveToHead(key);
         }
    }

private:
    unordered_map<int, list<Cache>::iterator> m_map;
    list<Cache> m_LRU_cache;
    int capacity_;
    
    void MoveToHead(int key) {
        //Move key from current location to head
        auto updateEntry = *m_map[key];
        m_LRU_cache.erase(m_map[key]);
        m_LRU_cache.push_front(updateEntry);
        m_map[key] = m_LRU_cache.begin();
    }
};
