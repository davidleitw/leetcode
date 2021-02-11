#include <bits/stdc++.h>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class LRUCache {
private:
    int cap;
    list<int> recent;
    unordered_map<int, int> cache;
    unordered_map<int, list<int>::iterator> hashMap;
    
    // 把指定的key放到最後面
    void use(int key) {
        if(hashMap.find(key) != hashMap.end()) {
            recent.erase(hashMap[key]);
        } else if(recent.size() >= cap) {
            int shouldDeleteKey = recent.back();
            recent.pop_back();
            cache.erase(shouldDeleteKey);
            hashMap.erase(shouldDeleteKey);
        }
        
        recent.push_front(key);
        hashMap[key] = recent.begin();
    }
public:
    LRUCache(int capacity) {
        cap = capacity;     
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            use(key);
            return cache[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        use(key);
        cache[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */