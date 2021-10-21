class RandomizedSet {
public:
    /** Initialize your data structure here. */
    set<int> s1;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s1.find(val)!=s1.end()){
           
            return false;
        }
        s1.insert(val);
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(s1.find(val)!=s1.end()){
            s1.erase(s1.find(val));
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom(){
        if(s1.size()==0){
            return -1;
        }
        int i=rand()%s1.size();
        auto it=next(s1.begin(), i);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */