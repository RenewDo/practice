class LRUCache{
public:
    LRUCache(int capacity) {
     this->capacity = capacity;
    }
    
    int get(int key) {
        if(cacheMap.find(key)== cacheMap.end())
             return -1;
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->value;
    }
    
    void set(int key, int value) {
        if(cacheMap.find(key)==cacheMap.end())
        {
            if(cacheMap.size()==capacity)
            {
                cacheMap.erase(cacheList.back().key);
                 cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key,value));
            cacheMap[key] = cacheList.begin();
        }
        else
        {
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        }
        
    }
private:
 struct CacheNode
 {
     int key;
     int value;
     CacheNode(int k, int v):key(k), value(v){}
 };
 int capacity;
 list<CacheNode> cacheList;
 unordered_map<int, list<CacheNode>::iterator> cacheMap;
};
