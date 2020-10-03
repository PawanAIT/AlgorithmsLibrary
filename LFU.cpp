class LFUCache {
public:
    
    int cap;
    int minfreq = 0;
    unordered_map<int, int> cacheKeyFreq; 
    unordered_map<int, list<pair<int, int> > > frqList;
    unordered_map<int, list<pair<int, int> >::iterator > keyAddr;
    
    
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    void add(int key, int value, int freq) {
        cacheKeyFreq[key] += 1;
        auto it = frqList[freq].insert(frqList[freq].end(), {key, value});
        keyAddr[key] = it;
    }
    
    void updateMinFreq() {
        if(frqList[minfreq].size() == 0)
        {
            frqList.erase(minfreq);
            minfreq += 1; // it will always be increased to plus one
        }
    }
    
    void remove(int key, int freq) {
        auto it = keyAddr[key];
        frqList[freq].erase(it);
        keyAddr.erase(key);
        updateMinFreq();
    }
    
    void evict() {
        auto minEleIt = frqList[minfreq].begin();
        int key = minEleIt->first;
        remove(key, minfreq);
        cacheKeyFreq.erase(key);
    }
    
    int get(int key) {
        if(cacheKeyFreq.count(key) > 0)
        {
            int freq = cacheKeyFreq[key];
            int value = keyAddr[key]->second;
            remove(key, freq);
            add(key, value, freq + 1);
            return value;
        }
        return -1;
    }
    
    
    void put(int key, int value) {
        if(cap == 0)
            return;
        
        if(cacheKeyFreq.count(key) == 0)
        {
            if(cap == cacheKeyFreq.size())
                evict();
            minfreq = 1;
            add(key, value, minfreq);
            return;
        }
        
        int lastFreq = cacheKeyFreq[key];
        remove(key, lastFreq);
        add(key, value, lastFreq + 1);
    }
};
