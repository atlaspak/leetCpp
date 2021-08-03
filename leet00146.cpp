class LRUCache {
    struct Node
    {
        int key;
        int value;
    };
public:
    LRUCache(int capacity) : 
        memSize(capacity)
    {

    }
    
    int get(int key) 
    {
        auto valItr = lruMap.find(key);
        int retVal = -1;
        if(valItr == lruMap.end())
        {
            return retVal;
        }
        retVal = valItr->second->value;
        lruQue.erase(valItr->second);
        lruQue.push_front({key, retVal});
        valItr->second = lruQue.begin();
        return retVal;
    }
    
    void put(int key, int value) 
    {
        auto valItr = lruMap.find(key);
        if(valItr != lruMap.end())
        {
            lruQue.erase(valItr->second);
            lruQue.push_front({key, value});
            valItr->second = lruQue.begin();
            return;
        }
        else if(lruQue.size() >= memSize)
        {
            lruMap.erase(lruQue.back().key);
            lruQue.pop_back();
        }
        lruQue.push_front({key, value});
        lruMap[key] = lruQue.begin();
    }
private:
    unordered_map<int,list<Node>::iterator> lruMap;
    list<Node> lruQue;
    int memSize;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
