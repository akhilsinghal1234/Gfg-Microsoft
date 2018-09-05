
deque<int> lru;
map<int, int> mp;
int size;

LRUCache::LRUCache(int N)
{
     //Your code here
    size = N;
}
/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) 
{
    int key;
    if(mp.find(x) == mp.end()){
        if(lru.size() == size){
            key = lru.front();
            mp.erase(key);
            lru.pop_front();
        }
        lru.push_back(x);
        mp[x] = y;
    }
    else{
        vector<int> vals;
        while(lru.front() != x){
            key = lru.front();
            vals.push_back(key);
            lru.pop_front();
        }
        lru.pop_front();
        for(int i = 0; i < vals.size(); i++)
            lru.push_front(vals[vals.size()-i-1]);
        lru.push_back(x);
        mp[x] = y;
    }
     //Your code here
}
/*Returns the value of the key x if 
present else returns -1 */

int LRUCache::get(int x)
{
    if(mp.find(x) == mp.end())
        return -1;
    else{
        int key;
        queue<int> q;
        while(lru.front() != x){
            key = lru.front();
            q.push(key);
            lru.pop_front();
        }
        lru.pop_front();
        while(q.empty() != true){
            key = q.front();
            q.pop();
            lru.push_front(key);
        }
        lru.push_back(x);
        return mp[x];
    }
    //Your code here
}