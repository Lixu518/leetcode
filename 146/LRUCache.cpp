#include<unordered_map>
#include<iostream>
#include<utility>
#include<list>
using namespace std;
class LRUCache{
    private:
        int size;
        list<pair<int, int>>cache;
        unordered_map<int, list<pair<int, int>>::iterator>hash;
    public:
        LRUCache(int capacity){
            size = capacity;
        }
        int get(int key){
            auto it = hash.find(key);
            if(it == hash.end()) return -1;
            cache.splice(cache.begin(), cache, it->second);
            return it->second->second;
        }
        void put(int key, int value){
            auto it = hash.find(key);
            if(it != hash.end()){
               it->second->second = value;
               return cache.splice(cache.begin(), cache, it->second);
            }
            if( hash.size() + 1 >size){
                hash.erase(cache.back().first);
                cache.pop_back();
            }
            cache.insert(cache.begin(), make_pair(key, value));
            hash[key] = cache.begin();
        }
};

int main(){
    LRUCache cache(4);
    cache.put(1, 3);
    cache.put(2, 4);
    cache.put(3, 7);
    cache.put(4, 8);
    cout<<"cache.get(4):"<<cache.get(4)<<endl;
    cache.put(5, 9);
    return 0;
}
