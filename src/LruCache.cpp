// Source : https://leetcode.com/problems/lru-cache/
// Author : wind4869
// Date   : 2015-08-08

/********************************************************************************** 
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * 
 *               
 **********************************************************************************/
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (hashmap_.find(key) == hashmap_.end())
        	return -1;

        moreToHead(key);
        return hashmap_[key]->value_;
    }
    
    void set(int key, int value) {
    	if (hashmap_.find(key) == hashmap_.end()) {
    		Entry entry(key, value);
    		if (cache_.size() >= capacity_) {
    			hashmap_.erase(cache_.back().key_);
    			cache_.pop_back();
    		}

    		cache_.push_front(entry);
    		hashmap_[key] = cache_.begin();
    	} else {
    		hashmap_[key]->value_ = value;
    		moreToHead(key);
    	}
    }
private:
	struct Entry {
		int key_;
		int value_;
		Entry(int k, int v) : key_(k), value_(v) { }
	};

	unordered_map<int, list<Entry>::iterator> hashmap_;
	list<Entry> cache_;
	int capacity_;

	void moreToHead(int key) {
		Entry entry = *hashmap_[key];
		cache_.erase(hashmap_[key]);
		cache_.push_front(entry);
		hashmap_[key] = cache_.begin();
	}
};

int main()
{

}
