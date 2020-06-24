/*************************************************************************
	> File Name: 380_insert_delete_getrandom.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  2/21 10:43:37 2017
 ************************************************************************/

#include<iostream>
using namespace std;

class RandomizedSet {
private:
    set<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(nums.find(val) == nums.end()){
            nums.insert(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        for(auto i = nums.begin(); i != nums.end(); i++){
            if(*i == val){
                nums.erase(i);
                return true;
            }
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int len = rand() % nums.size();
        auto i = nums.begin();
        for(int j = 0; j < len; j++, i++);
        return *i;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
