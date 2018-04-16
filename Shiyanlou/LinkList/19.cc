#include<iostream>
#include<list>
#include<map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _capacity = capacity;    
    }
    
    int get(int key) {
        auto search = Cache.find(key);
        if(search == Cache.end()) return -1;
        touch(search);
        return search->second->second;
    }
    
    void put(int key, int value) {
        auto search = Cache.find(key);
        if(search != Cache.end()){
            search->second->second = value;
            touch(search);
            return ;
        }
        if(_capacity == List.size()){
            int toDelete = List.back().first;
            Cache.erase(Cache.find(toDelete));
            List.pop_back();
        }
        List.push_front({key, value});
        Cache[key] = List.begin();
    }

private:
    // typedef pair<int, int> NODE;
    typedef list<pair<int, int>> LIST;
    typedef map<int, LIST::iterator> CACHE;

    CACHE Cache;
    LIST List;
    int _capacity;

    touch(CACHE::iterator search){
        pair <int, int> temp = * search->second;
        List.erase(search->second);
        List.push_front(temp);
        Cache[search->first] = List.begin();
    }
};

int main(){
    LRUCache test(3);
    test.put(1,2);
    cout << test.get(1) << endl;
    
    test.put(2,2);
    test.put(3,3);
    test.put(4,4);
    cout << test.get(1) << endl;
    cout << test.get(2) << endl;
    test.put(5,5);
    cout << test.get(3) << endl;
    return 0;
}