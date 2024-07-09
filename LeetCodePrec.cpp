#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>

using namespace std;

class RandomizedSet {
public:
    map<int,int>m;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()){
            m.insert(make_pair(val,1));
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        if(m.find(val) != m.end()){
            m.erase(m.find(val));
            return true;
        }else{
            return false;
        }
    }
    
    int getRandom() {
        random_device rd;
        mt19937 mt(rd());
        uniform_int_distribution<int> dist(0,m.size()-1);
        auto randNum = dist(mt);
        map<int,int>::iterator iter = m.begin();
        for(int i = 0 ; i<randNum ;i++){
            iter++;
        }
        return iter->first; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

