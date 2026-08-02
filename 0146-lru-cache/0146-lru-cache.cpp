class LRUCache {
public:
    list<int> dll; // doubly linked list of keys (most recent at front)
    map<int, pair<list<int>::iterator, int>> cache; // key → {iterator, value}
    int capacity;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    void makeMostRecentlyUsed(int key) {
        dll.erase(cache[key].first);       // remove old position
        dll.push_front(key);               // move to front
        cache[key].first = dll.begin();    // update iterator
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        makeMostRecentlyUsed(key);
        return cache[key].second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].second = value;
            makeMostRecentlyUsed(key);
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            if (dll.size() > capacity) {
                int key_delete = dll.back();
                dll.pop_back();
                cache.erase(key_delete);
            }
        }
    }
};
