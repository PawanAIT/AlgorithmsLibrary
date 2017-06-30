/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/

/*You are required to complete below methods */

list<pair<int,int>> L;
int cacheSize;
unordered_map<int,list<pair<int,int>>::iterator> M;

/*Inititalize an LRU cache with size N */
LRUCache::LRUCache(int N)
{
     //Your code here
     cacheSize = N;
     L.clear();
     M.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
     //Your code here
     if(M.find(x) == M.end()){
         
         if(L.size() < cacheSize){
             M[x] = L.insert(L.end(),{x,y});
         }
         else{
            list<pair<int,int>>::iterator it = L.begin();
            int key = it->first;
            L.erase(it);
            M.erase(key);
            M[x] = L.insert(L.end(),{x,y});
         }
         
     }
     else{
         list<pair<int,int>>::iterator it = M[x];
         L.erase(it);
         M[x] = L.insert(L.end(),{x,y});
         
     }
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x)
{
    //Your code here
    if(M.find(x) == M.end()){
        return -1;
    }
    else{
        list<pair<int,int>>::iterator it = M[x];
        int y = it->second;
        L.erase(it);
        M[x] =  L.insert(L.end(),{x,y});
        return y;
    }
    
}