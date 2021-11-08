class Solution {
public:
    unordered_map<int,int> um1;
    int numTreesUtil(int n){
        
        if(um1.find(n)==um1.end()){
            for(int i=1; i<=n; i++){
                um1[n] += numTreesUtil(i-1)*numTreesUtil(n-i);
            }
        }
        return um1[n];
        
    }
    int numTrees(int n) {
        
        um1[0] = 1;
        um1[1] = 1;
        um1[2] = 2;
        
        return numTreesUtil(n);
       
        
    }
};