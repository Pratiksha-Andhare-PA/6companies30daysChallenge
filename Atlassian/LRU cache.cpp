class LRUCache {
public:
    list<int> LRUlist; //doubly linked list container
    unordered_map<int, pair<int, list<int>::iterator>> mp;
    int size;

    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            LRUlist.erase(mp[key].second);
            LRUlist.push_front(key);
            mp[key].second = LRUlist.begin();

            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){ //key already exist
            mp[key].first = value;
            LRUlist.erase(mp[key].second);
            LRUlist.push_front(key);
            mp[key].second = LRUlist.begin();
        }
        else{
            if(mp.size() == size){
                int lastKey = LRUlist.back();
                mp.erase(lastKey);
                LRUlist.pop_back();
            }
            LRUlist.push_front(key);
            mp[key] = {value, LRUlist.begin()};
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
