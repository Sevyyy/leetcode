class LRUCache {
private:
    int capacity;
    map<int, int> data;
    list<int> l;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto iter = data.find(key);
        if(iter != data.end())
        {
            l.remove(iter->first);
            l.push_front(iter->first);
            return iter->second;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        int length = data.size();
        auto iter = data.find(key);
        if(iter != data.end())
        {
            data[key] = value;
            l.remove(key);
            l.push_front(key);
        }
        else
        {
            if(length >= capacity)
            {
                data.erase(l.back());
                l.pop_back();
            }
            l.push_front(key);
            data[key] = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */